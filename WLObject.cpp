#include <iostream>
#include "WLObject.h"

using namespace std; 

//IMPLEMENT_SINGLETON(aSingleton)

unsigned int WLObject::numberOfInstances = 0;


WLObject::WLObject()
{ 
    numberOfInstances++;
	//cout << "aObject" << endl;
	count = 0;
    name[0] = '\0';
	retain(); 
}
WLObject::~WLObject()
{
    numberOfInstances--;
	//cout << "~aObject " << name << endl;
}

void WLObject::retain() 
{ 
	count++; 
	//cout << "Retain " << name << " : " << count << endl;
}
	
void WLObject::release() 
{ 
    --count;
    //cout << "Retain " << name << " : " << count << endl;

	if( !count )
	{
		delete this;
	}
}

unsigned int WLObject::instances()
{
    return numberOfInstances;
}

