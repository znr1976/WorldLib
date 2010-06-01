/*
 *  WLTest.h
 *  GLSandbox
 *
 *  Created by zen1976
 */
#ifndef __WL_TEST_H__
#define __WL_TEST_H__

#include <stdio.h>

#include "WLObject.h"

typedef enum WLTestResult
{
    WLTEST_PASS,
    WLTEST_FAIL
};

#define WL_TEST_CHECK(a) \
do{ \
    incrementChecks(); \
    if( !(a) ) \
        failedCheck( __FILE__, __LINE__, #a ); \
}while(0)


class WLTest
{
    friend class WLTestRunner;
public:
    WLTest() { checks = 0; failed = 0; }
    ~WLTest() { }
    virtual void setup() = 0;
    virtual void teardown() = 0;
    virtual WLTestResult run() = 0;
    
    void results()
    {
        printf("FAILED = %d (checks performed = %d)\n", failed, checks );
    }
    
protected:
    void incrementChecks()
    {
        checks++;
    }
    void failedCheck( const char* fileName, int lineNo, const char* failedAssert )
    {
        printf("FAILED->  WL_TEST_CHECK(%s) [%s:%d]\n", failedAssert, fileName, lineNo );
        failed++;
    }
private:
    unsigned int checks;
    unsigned int failed;
};


class WLTestRunner
{
public:
    WLTestRunner() {} 
    ~WLTestRunner() {}
    void run( WLTest* t )
    {
        int beginningInstancesCount = WLObject::instances();
        t->setup();
        t->run();
        t->teardown();
        if( beginningInstancesCount != WLObject::instances() )
        {
            t->failedCheck(__FILE__, __LINE__, "MEMORY LEAK");
        }
        t->results();
    }
    
};

#endif