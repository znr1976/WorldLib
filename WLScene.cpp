/*
 *  WLScene.cpp
 *  GLSandbox
 *
 *  Created by zen1976 on 6/25/09.
 */

#include "WLScene.h"

WLScene::WLScene()
{
    primitives = new WLList();
}

WLScene::~WLScene()
{
    delete primitives;
}

void WLScene::draw()
{
    WLListIterator& it = primitives->iterator();

    for( it.begin(); *it != 0; ++it )
    {
        dynamic_cast<WLPrimitive*> (*it)->draw();
    }
}

void WLScene::addPrimitive( WLPrimitive* p ) 
{ 
    primitives->addItem(p);
}
