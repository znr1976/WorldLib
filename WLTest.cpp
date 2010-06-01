/*
 *  WLTest.cpp
 *  GLSandbox
 *
 *  Created by zen1976
 */

#include "WLTest.h"
#include "TestWLList.h"

int main( int argc, char* argv[] )
{
    WLTestRunner runner;
    TestWLList* test =  new TestWLList();
    runner.run( test );
    delete test;
}