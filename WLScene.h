/*
 *  WLScene.h
 *  GLSandbox
 *
 *  Created by zen1976 on 6/25/09.
 */

#ifndef __WL_SCENE_H_INCLUDED__
#define __WL_SCENE_H_INCLUDED__

#include "WLObject.h"
#include "WLList.h"
#include "WLSolids.h"

class WLScene : public WLObject
{
    enum  WLSceneOperations {
        WL_SCENE_PUSH,
        WL_SCENE_POP,
        WL_SOLID_TRANSLATE,
        WL_SOLID_ROTATE,
        WL_SOLID_SCALE
    };
    
public:
    WLScene();
    virtual ~WLScene(); // FIXME
    void draw();
    void addPrimitive( WLPrimitive* p );
private:
    WLList* primitives;
};

#endif // __WL_SCENE_H_INCLUDED__