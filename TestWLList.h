/*
 *  TestWLList.h
 *  GLSandbox
 *
 *  Created by zen1976
 */
#include "AMLTest.h"
#include "AMLList.h"

class AMLNamedObject: public AMLObject
{
public:
    AMLNamedObject() : AMLObject() {}
    virtual ~AMLNamedObject() { }
    
public:
    virtual void setName( const char* instanceName ) { strncpy(name, instanceName, INSTANCE_NAME_SIZE); }
    char* getName() { return name; }
    
private:
    char name[INSTANCE_NAME_SIZE];
};

class TestWLList : public AMLTest
{
public:
    TestWLList()
    {
        
    }
    
    ~TestWLList()
    {
        
    }
    void setup();
    void teardown();
    virtual AMLTestResult run();
    
private:
    
    AMLList* list;
};
