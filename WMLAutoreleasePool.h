/*
 *  WLAutoreleasePool.h
 *  GLSandbox
 *
 *  Created by zen1976
 */

#ifndef __WL_AUTORELEASE_POOL_H_INCLUDED__
#define __WL_AUTORELEASE_POOL_H_INCLUDED__

#include "WLObject.h"
#include "WLList.h"

class WLAutoreleasePool : public WLObject {
    void addObject( WLObject* o ) { list->addItem( o ); }
    void flush();
private:
    WLList* list;
};

#endif // __WL_AUTORELEASE_POOL_H_INCLUDED__