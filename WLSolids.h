/*
 *  WLSolids.h
 *  GLSandbox
 *
 *  Created by zen1976
 */
#ifndef __SOLIDS_H_588745C3_B5D1_4A95_B186_D1B6CC0A9E1B
#define __SOLIDS_H_588745C3_B5D1_4A95_B186_D1B6CC0A9E1B

#include "WLObject.h"
#include "WLTexture.h"
#include "WLPrimitives.h"
#include "WLTriangleMeshBuffer.h"
#include "WLList.h"

class WLSolid : public WLPrimitive
{
    
public:
    WLSolid();
    virtual ~WLSolid() { if( textlist ) textlist->release(); }
    virtual void draw() = 0;
    virtual void attachTexture( WLTexture* _text );
protected:
    WLList* textlist;
    int currentOperation;
};

class WLCube : public WLSolid
{
public:
    WLCube( );
    virtual ~WLCube();
    virtual void draw();

protected:
    const static WLPoint3D corners[8];
    const static unsigned char indexes[24];
    const static WLPoint2D texverts[4];

};

class WLPyramid: public WLSolid
{
public:
    WLPyramid();
    virtual ~WLPyramid();
    virtual void draw();
};

class WLGrid : public WLSolid {
public:
    WLGrid( float xDots, float yDots );

    virtual ~WLGrid();
    virtual void draw();
private:
    float xDots, yDots;
};

class WLTriangleMesh : public WLSolid {
public:
    WLTriangleMesh( WLTriangleMeshBuffer* _buffer ) { buffer = _buffer; buffer->retain(); }
    
    virtual ~WLTriangleMesh() { buffer->release(); }
    virtual void draw();
private:
    WLTriangleMeshBuffer* buffer;
};

#endif //__SOLIDS_H_588745C3_B5D1_4A95_B186_D1B6CC0A9E1B