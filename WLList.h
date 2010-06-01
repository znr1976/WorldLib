/*
 *  WLList.h
 *  GLSandbox
 *
 *  Created by zen1976
 *
 */
#ifndef __WL_LIST_H__
#define __WL_LIST_H__

#include "WLObject.h"

class WLListIterator;

class WLList : public WLObject
{
    friend class WLListIterator;
public:
    WLList();
    virtual ~WLList();

    void addItem( WLObject* item, int index = -1 );  // insert at the tail by default
    WLObject* getItem( int index = 0 ) const;
    void deleteItem( int index = 0 );
    int size() const { return numOfItems; }
    WLListIterator& iterator() const;
    
protected:
    
    struct WLNode
    {
        WLNode* prev;
        WLNode* next;
        WLObject* data;
    };
    
    WLNode* getNode( int index ) const;
        
    WLNode *head, *tail;
    int numOfItems;
};


class WLListIterator
{
public:
    
    WLListIterator( const WLList* const _list ) { list = _list; current = list->head; }
    ~WLListIterator();
    WLListIterator& operator++ ( ) { if( current ) current = current->next; return *this; }
    WLObject* operator* () { if( current ) return current->data; else return 0; }
    bool operator== (const WLListIterator& op) const { if( this->list == op.list && this->current == op.current ) return 1; else return 0; }
    bool operator!= (const WLListIterator& op) const { return !this->operator==( op ); }

    void begin() { current = list->head; }
    
    void end() { current = list->tail; }
    
    
private:
    const WLList* list;
    WLList::WLNode* current;
};

#endif // __WL_LIST_H__