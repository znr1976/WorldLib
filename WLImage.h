//
//  WLImage.h
//  GLSandbox
//
//  Created by zen1976.
//
#ifndef __WL_IMAGE_H_INCLUDED__
#define __WL_IMAGE_H_INCLUDED__

#include "WLObject.h"

class WLImage : public WLObject
{
public:
    typedef struct  {
        unsigned int width;
        unsigned int height;
    } WLImageInfo;

    WLImage( const char* fileName );
    ~WLImage();
    void load();
    WLImageInfo getInfo();
    void* getBuffer();
    
private:
    CIImage* image;
    NSString* fileName;
    NSBitmapImageRep* bitmapImageRep;
    
};

#endif // __WL_IMAGE_H_INCLUDED__