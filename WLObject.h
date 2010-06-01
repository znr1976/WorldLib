#ifndef __OBJECT_H_588745C3_B5D1_4A95_B186_D1B6CC0A9E1B
#define __OBJECT_H_588745C3_B5D1_4A95_B186_D1B6CC0A9E1B

#include <string.h>

#define INSTANCE_NAME_SIZE 32

#define GL_PI 3.1415
typedef struct
{
    float x;
    float y;
} WLPoint2D;


typedef struct
{
    float x;
    float y;
    float z;
} WLPoint3D;

// A vertex is a point in 3D + the texture coord
typedef struct  {
    WLPoint3D point;
    WLPoint2D textCoord;
} WLVertex;


class WLObject
{
public:
	WLObject();
	virtual ~WLObject();

public:
    virtual void setName( const char* instanceName ) { strncpy(name, instanceName, INSTANCE_NAME_SIZE); }
    char* getName() { return name; }
	virtual void retain();
	virtual void release();
    static unsigned int instances();

	
private:
    char name[INSTANCE_NAME_SIZE];
	int count;
    static unsigned int numberOfInstances;
};

#define DECLARE_SINGLETON( typeName ) \
private: \
	typeName(); \
	virtual ~typeName(); \
	typeName( const typeName& ); \
public: \
	static typeName* getInstance(); \
private: \
    static typeName* instance;
	
#define IMPLEMENT_SINGLETON_NO_CONSTRUCTORS( typeName ) \
    typeName* typeName::instance; \
	typeName* typeName::getInstance() \
    { if (typeName::instance == 0 ) typeName::instance = new typeName(); return typeName::instance; } \

#define IMPLEMENT_SINGLETON( typeName ) \
		IMPLEMENT_SINGLETON_NO_CONSTRUCTORS( typeName ) \
		typeName::typeName( ) {} \
		typeName::typeName( const typeName& ) {} \
		typeName::~typeName() {} 
		
/*
class aSingleton : public aObject
{
	DECLARE_SINGLETON(aSingleton)	
};
*/
#endif __OBJECT_H_588745C3_B5D1_4A95_B186_D1B6CC0A9E1B
