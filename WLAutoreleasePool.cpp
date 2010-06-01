/*
 *  WLAutoreleasePool.cpp
 *  GLSandbox
 *
 *  Created by zen1976.
 */

#include "WLAutoreleasePool.h"

void WLAutoreleasePool::flush()
{
    WLListIterator it = list->iterator();
    for( it.begin(); *it != 0; ++it )
    {
        (*it)->release();
    }
}