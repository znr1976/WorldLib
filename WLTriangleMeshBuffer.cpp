/*
 *  WLTriangleMeshBuffer.cpp
 *  GLSandbox
 *
 *  Created by zen1976
 */

#include "WLTriangleMeshBuffer.h"
#include <stdlib.h>

void WLTriangleMeshBuffer::readOneLineFromFile( FILE* fp, char* string )
{
    do
    {
        fgets( string, 255, fp );
    } while( ( string[ 0 ] == '/' ) || ( string[ 0 ] == '\n' ) );

    return;
}

WLTriangleMeshBuffer::WLTriangleMeshBuffer( char* fileName ): triangles(0)
{
    FILE *filein;
    char oneline[ 255 ];
    int triloop, vertloop;
    float x, y, z, u, v;
    
    filein = fopen( fileName, "rt" );
    
    if( !filein )
    {
        printf("cannot find file: %s\n", fileName);
        return;
    }
    readOneLineFromFile( filein, oneline );
    sscanf( oneline, "NUMPOLLIES %d\n", &numTriangles );
    triangles = (WLTriangle*) calloc( numTriangles, sizeof( WLTriangle ) );
    // Step through each triangle in sector
    for( triloop = 0; triloop < numTriangles; triloop++ )
    {
        readOneLineFromFile( filein, oneline );
        sscanf(oneline, "Tri %d", &(triangles[triloop].textureNumber) );
        // Step through each vertex in triangle
        for( vertloop = 0; vertloop < 3; vertloop++ )
        {
            readOneLineFromFile( filein, oneline );
            sscanf( oneline, "%f %f %f %f %f", &x, &y, &z, &u, &v );
            // Store values into respective vertices
            triangles[ triloop ].vertex[ vertloop ].point.x = x;
            triangles[ triloop ].vertex[ vertloop ].point.y = y;
            triangles[ triloop ].vertex[ vertloop ].point.z = z;
            triangles[ triloop ].vertex[ vertloop ].textCoord.x = u;
            triangles[ triloop ].vertex[ vertloop ].textCoord.y = v;
        }
    }
    fclose( filein );
    
    return;
}

WLTriangleMeshBuffer::~WLTriangleMeshBuffer()
{
    if( triangles != 0 )
    {
        free( triangles );
    }
}
