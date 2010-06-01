/*
 *  TestWLList.cpp
 *  GLSandbox
 *
 *  Created by zen1976.
 */

#include "TestWLList.h"

void TestWLList::setup()
{
    list = new AMLList();
}

void TestWLList::teardown()
{
    list->release();        
}

AMLTestResult TestWLList::run()
{
    // Few simple insertions and deletions
    AMLObject* p = new AMLObject();
    p->setName("First");
    
    list->addItem(p, 0);
    p->release();
    AML_TEST_CHECK( list->size() == 1 );
    
    p = new AMLObject();
    p->setName("Second");
    list->addItem(p, 0);
    p->release();
    
    AML_TEST_CHECK( !strcmp( list->getItem(0)->getName(), "Second" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(1)->getName(), "First" ) );   
    AML_TEST_CHECK( list->size() == 2 );

    
    list->deleteItem(0);
    AML_TEST_CHECK( !strcmp( list->getItem(0)->getName(), "First" ) );
    AML_TEST_CHECK( list->size() == 1 );
    list->deleteItem(0);
    
    // insert 10 objects
    for( int i = 0; i < 10; i++ )
    {
        p = new AMLObject();
        list->addItem(p, 0);
        p->release();
        AML_TEST_CHECK( list->size() == (i+1) );
    }
    
    // delete 10 obj
    for( int i = 10; i > 0; i-- )
    {
        list->deleteItem(0);
        AML_TEST_CHECK( list->size() == (i-1) );
    }

    // insert 10 objects
    for( int i = 0; i < 10; i++ )
    {
        p = new AMLObject();
        list->addItem(p, 0);
        p->release();
        AML_TEST_CHECK( list->size() == (i+1) );
    }
    
    {
        int i = 0;
        AMLListIterator it = list->iterator();        
        for( it.begin(); *it != 0; ++it )
        {
            i++;
        }
        AML_TEST_CHECK( i == list->size() );
    }    
    
    
    p = new AMLObject();
    p->setName("BEFORE");
    
    list->addItem(p, 5);
    p->release();
    AML_TEST_CHECK(list->size() == 11 );
    AML_TEST_CHECK( !strcmp( list->getItem(5)->getName(), "BEFORE" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(-6)->getName(), "BEFORE" ) );    
    list->deleteItem(5);
    
    p = new AMLObject();
    p->setName("AFTER");
    list->addItem(p, -6);
    p->release();
    AML_TEST_CHECK(list->size() == 11 );
    AML_TEST_CHECK( !strcmp( list->getItem(5)->getName(), "AFTER" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(-6)->getName(), "AFTER" ) );    
    list->deleteItem(5);
    
    p = new AMLObject();
    p->setName("SECOND");
    list->addItem(p, -10);
    p->release();
    AML_TEST_CHECK(list->size() == 11 );
    AML_TEST_CHECK( !strcmp( list->getItem(1)->getName(), "SECOND" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(-10)->getName(), "SECOND" ) );    
    list->deleteItem(-10);
    
    p = new AMLObject();
    p->setName("FIRST");
    list->addItem(p, 0);
    p->release();
    AML_TEST_CHECK(list->size() == 11 );
    AML_TEST_CHECK( !strcmp( list->getItem(0)->getName(), "FIRST" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(-11)->getName(), "FIRST" ) );    
    list->deleteItem(-11);

    p = new AMLObject();
    p->setName("SECONDLAST");
    list->addItem(p, 9);
    p->release();
    AML_TEST_CHECK(list->size() == 11 );
    AML_TEST_CHECK( !strcmp( list->getItem(9)->getName(), "SECONDLAST" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(-2)->getName(), "SECONDLAST" ) );    
    list->deleteItem(-2);
    
    p = new AMLObject();
    p->setName("LAST");
    list->addItem(p, -1);
    p->release();
    AML_TEST_CHECK(list->size() == 11 );
    AML_TEST_CHECK( !strcmp( list->getItem(10)->getName(), "LAST" ) );
    AML_TEST_CHECK( !strcmp( list->getItem(-1)->getName(), "LAST" ) );    
    list->deleteItem(-1);
    
    return AMLTEST_PASS;
}