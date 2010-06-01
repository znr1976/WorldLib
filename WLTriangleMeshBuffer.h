/*
 *  WLTriangleMeshBuffer.h
 *  GLSandbox
 *
 *  Created by zen1976
 */

#include "WLObject.h"
#include <stdio.h>

class WLTriangleMeshBuffer: public WLObject
{
    typedef int WLTextureId;
    typedef struct
        {
            WLVertex vertex[ 3 ];
            WLTextureId textureNumber;
        } WLTriangle;
public:
    WLTriangle*   triangles;
    long numTriangles;

    WLTriangleMeshBuffer( char* fileName );
    WLTriangleMeshBuffer( void* buf );
    virtual ~WLTriangleMeshBuffer();
private:
    void readOneLineFromFile( FILE* fp, char* string );
};