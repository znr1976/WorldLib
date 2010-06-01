//
//  WLImage.mm
//  GLSandbox
//
//  Created by zen1976.
//

#import "WLImage.h"
#import "QuartzCore/CIImage.h"


WLImage::WLImage( const char* _fileName )
{
     fileName = [[NSString alloc] initWithCString: _fileName ];
}

WLImage::~WLImage()
{
    [fileName release];
    [image release];
    [bitmapImageRep release];
}

void WLImage::load()
{
    image = [[CIImage alloc] initWithContentsOfURL:[NSURL fileURLWithPath: fileName] ];
    bitmapImageRep = [[NSBitmapImageRep alloc] initWithCIImage:image];
}

WLImage::WLImageInfo WLImage::getInfo()
{
    unsigned int bpp =  [bitmapImageRep bitsPerPixel];
    unsigned int bytesPerPlane =  [bitmapImageRep bytesPerPlane];
    unsigned int bytesPerRow = [bitmapImageRep bytesPerRow];
    unsigned int isPlanar = [bitmapImageRep isPlanar];  
    unsigned int numberOfPlanes  = [bitmapImageRep numberOfPlanes];
    unsigned int samplesPerPixel = [bitmapImageRep samplesPerPixel];  

    WLImage::WLImageInfo info;
    
    if( bpp 
        && bytesPerRow )
    {
    
        printf("biSize = %d x %d %d %d %d\n",
               bytesPerRow / (bpp / 8 ),      // width
               bytesPerPlane / bytesPerRow,   // height
               isPlanar,
               samplesPerPixel, 
               numberOfPlanes );
        info.width = bytesPerRow / (bpp / 8 );
        info.height = bytesPerPlane / bytesPerRow;
        
    }
    else
    {
        printf("bpp = %d\nbytesPerRow = %d\n", bpp, bytesPerRow );
        info.width = 0;
        info.height = 0;
    }
    
    return info;
}

void* WLImage::getBuffer()
{
    return [bitmapImageRep bitmapData];
}
