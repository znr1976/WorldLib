/*
 *  WLPrimitives.h
 *  GLSandbox
 *
 *  Created by zen1976 on 6/27/09.
 */

#ifndef __WL_PRIMITIVES_H_INCLUDED__
#define __WL_PRIMITIVES_H_INCLUDED__

#include "OpenGL/gl.h"
#include "WLObject.h"
#include <stdio.h>

class WLPrimitive : public WLObject {
public:
    virtual void draw() = 0;
};


class WLPushOp : public WLPrimitive {
    DECLARE_SINGLETON(WLPushOp);
public:
    virtual void draw() { printf("Draw: glPushMatrix();\n"); glPushMatrix(); } 
};

class WLPopOp : public WLPrimitive {
    DECLARE_SINGLETON(WLPopOp);
public:
    virtual void draw() { printf("Draw: glPopMatrix();\n"); glPopMatrix(); } 
};

class WLRotate : public WLPrimitive {
public:
    WLRotate( float _deg, float _x, float _y, float _z ) { deg = _deg; x = _x; y = _y; z = _z; }
    virtual void draw() { printf("Draw: glRotatef();\n"); glRotatef( deg, x, y, z ); }
private:
    float deg;
    float x, y, z;
};

class WLTranslate : public WLPrimitive {
public:
    WLTranslate( float _x, float _y, float _z ) { x = _x; y = _y; z = _z; }
    virtual void draw() { printf("Draw: glTranslatef();\n"); glTranslatef( x, y, z ); }
private:
    float x, y, z;
};

class WLScale : public WLPrimitive {
public:
    WLScale( float _x, float _y, float _z ) { x = _x; y = _y; z = _z; }
    virtual void draw() { printf("Draw: glScalef();\n"); glScalef( x, y, z ); }
private:
    float x, y, z;
};

#endif // __WL_PRIMITIVES_H_INCLUDED__