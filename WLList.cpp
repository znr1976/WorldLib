/*
 *  WLList.cpp
 *  GLSandbox
 *
 *  Created by zen1976

 */

#include <string>
#include "WLList.h"

WLList::WLList()
{
    head = tail = (WLNode*) 0;
    numOfItems = 0;
}
WLList::~WLList()
{
    while( size() )
    {
        deleteItem(0);
    }
}

void WLList::deleteItem( int index )
{
    // find the item
    WLNode* p = getNode(index);
    
    if( p == (WLNode*) 0 )
    {
        return;
    }
        
    // unlink
    if( p->prev )
    {
        p->prev->next = p->next;
    }
    else
    {
        // we've gotta be at the beginning
        head = p->next;
    }
    
    if( p->next )
    {
        p->next->prev = p->prev;
    }
    else
    {
        // we've gotta be at the end
        tail = p->prev;
    }
    
    // release the object instance
    // we no longer have a reference to it
    p->data->release();
    
    // free the WLNode
    delete p;
    
    numOfItems--;
}

void WLList::addItem( WLObject* item,  int index )
{
    WLNode* p = new WLNode();
    WLNode* where = getNode(index);
    
    if( where == (WLNode*) 0 )
    {
        // couldn't find the item
        if( index != 0 
            && index != -1 )
        {
            printf("not added\n");
            delete p;
            return;
        }
        
        // insert the first item
        head = tail = p;
        p->next = p->prev = (WLNode*) 0;
    }
    else
    {
        if( index >= 0 )
        {
            // insert before
            p->prev = where->prev;
            p->next = where;
            p->next->prev = p;
            
            if( p->prev )
            {
                p->prev->next = p;
            }
            else
            {
                head = p;
            }
        }
        else
        {
            // insert after
            p->next = where->next;
            p->prev = where;
            p->prev->next = p;
            
            if( p->next )
            {
                p->next->prev = p;
            }
            else
            {
                tail = p;
            }
        }
    }
    
    p->data = item;
    p->data->retain();
    numOfItems++;
}

WLList::WLNode* WLList::getNode( int index ) const
{
    // out-of-bounds check
    if( ( index > size() - 1 )
       || ( index < -size() ) )
    {
        return (WLNode*) 0;
    }
    
    
    if( index >= 0 )
    {
        WLNode* p = head;
        
        while( index-- )
        {
            p = p->next;
        }
        return p;
    }
    else
    {
        WLNode* p = tail;
        
        index = (-index) - 1;
        while( index-- )
        {
            p = p->prev;
        }
        return p;
    }
}

WLObject* WLList::getItem( int index ) const
{
    WLNode* p = getNode( index );
    
    if ( p != (WLNode*) 0 )
    {
        return p->data;
    }
    
    return (WLObject*) 0;
}

WLListIterator& WLList::iterator() const
{
    return *(new WLListIterator( this ));
}

WLListIterator::~WLListIterator()
{
    printf("Iterator going out of scope\n");
}
