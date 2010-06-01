/*
 *  Solids.cpp
 *  GLSandbox
 *
 *  Created by zen1976
 */

#include "WLSolids.h"
#include "OpenGl/gl.h"
#include "OpenGL/glu.h"
#include "stdio.h"
#include <string.h>
#include "math.h"

#pragma mark WLSolid

WLSolid::WLSolid() : WLPrimitive()
{
    textlist = 0;
}

void WLSolid::attachTexture( WLTexture* _text )
{
    if( !textlist )
    {
        textlist = new WLList();
    }
    textlist->addItem(_text, -1);
}

const WLPoint3D WLCube::corners[8] =
{
    {-0.5f, +0.5f, +0.5f },
    {+0.5f, +0.5f, +0.5f },
    {+0.5f, -0.5f, +0.5f },
    {-0.5f, -0.5f, +0.5f },
    {-0.5f, +0.5f, -0.5f },
    {+0.5f, +0.5f, -0.5f },
    {+0.5f, -0.5f, -0.5f },
    {-0.5f, -0.5f, -0.5f },
};

const unsigned char WLCube::indexes[24] =
{
    0, 1, 2, 3, // Front
    4, 5, 1, 0, // Top
    3, 2, 6, 7, // Bottom
    5, 4, 7, 6, // Back
    1, 5, 6, 2, // Right
    4, 0, 3, 7, // Left
};


//        4    5
//
//   4    0    1    5    4
//
//   7    3    2    6    7
//
//        7    6
//

const WLPoint2D WLCube::texverts[4] = 
{
    {1.0f, 0.0f},
    {1.0f, 1.0f},
    {0.0f, 1.0f},
    {0.0f, 0.0f}
};

#pragma mark Cube
WLCube::WLCube( ): WLSolid()
{
}

WLCube::~WLCube( )
{
}

void WLCube::draw()
{
    printf("Draw: cube\n");
    if( textlist && textlist->getItem(0) )
    {
        ((WLTexture*)(textlist->getItem(0)))->enable();
    }
    
    glFrontFace(GL_CW);
    glBegin (GL_QUADS);
    for ( int face = 0; face < 6; face++ )
    {
        for( int i = 0; i < 4; i++ )
        {
            if ( textlist && textlist->getItem(0) )
            {
                // tex vertices
                glTexCoord2f ( 
                    texverts[i].x,
                    texverts[i].y );
            }
            
            // cube corners
            glVertex3f ( 
                corners[indexes[i+4*face]].x, 
                corners[indexes[i+4*face]].y, 
                corners[indexes[i+4*face]].z );
        }
    }
    glEnd ();
}

#pragma mark Pyramid
WLPyramid::WLPyramid()
:WLSolid()
{
    
}

WLPyramid::~WLPyramid()
{
    
}

void WLPyramid::draw()
{
    GLfloat x, y, angle;
    int iPivot = 1;
    printf("Draw: pyramid\n");
    
    if( textlist->getItem(0) )
    {
        ((WLTexture*)(textlist->getItem(0)))->enable();
    }

    glFrontFace(GL_CW);
    glBegin(GL_TRIANGLE_FAN);
    if ( textlist->getItem(0) )
    {
        // tex vertices
        glTexCoord2f ( 0.5f, 0.5f );
        glColor3f( 1.0f, 1.0f, 1.0f );
    }
    else
    {
        glColor3f(1.0f, 1.0f, 0.0f);
    }
    
    glVertex3f(0.0f, 0.0f, 1.0f);
    
    for( angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0) )
    {
        x = 1.0f * sin( angle );
        y = 1.0f * cos( angle );
        
        if ( textlist->getItem(0) )
        {
            // tex vertices
            glTexCoord2f ( 0.5f+x/2.0f, 0.5f+y/2.0f );
        }        
        glVertex2f( x, y );
        
        if( !textlist->getItem(0) )
        {
            if( ( iPivot % 2 ) == 0 )
            {
                glColor3f(0.0f, 1.0f, 0.0f);
            }
            else
            {
                glColor3f(1.0f, 0.0f, 0.0f);
            }
        }
        else
        {
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        
        iPivot++;
        glVertex2f( x, y );
    }
    
    glEnd();
    iPivot = 0;
    glFrontFace(GL_CCW);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f);
    
    for( angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0) )
    {
        x = 1.0f * sin( angle );
        y = 1.0f * cos( angle );
        glVertex2f( x, y );
        
        if( ( iPivot % 2 ) == 0 )
        {
            glColor3f(0.0f, 1.0f, 0.0f);
        }
        else
        {
            glColor3f(1.0f, 0.0f, 0.0f);
        }
        
        iPivot++;
        glVertex2f( x, y );
    }
    
    glEnd();
}

#pragma mark Grid
WLGrid::WLGrid( float xDots, float yDots )
{
    this->xDots = xDots;
    this->yDots = yDots;
}


WLGrid::~WLGrid()
{
}

void WLGrid::draw( )
{
    printf("Draw: grid\n");
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POINTS);

    for( float xP = -0.5f; xP < 0.5f; xP += 1.0f/xDots )
    {
        for( float yP = -0.5f; yP < 0.5f; yP += 1.0f/yDots )
        {
            glVertex3f( xP, yP, 0.0f );
        }
    }
    
    glEnd();
}

void WLTriangleMesh::draw()
{
    printf("Draw: triangle mesh\n");
    if( textlist->getItem(0) )
    {
        ((WLTexture*)(textlist->getItem(0)))->enable();
    }
    
    glDisable(GL_CULL_FACE);
    glPolygonMode(GL_BACK, GL_FILL);
    
    for( int i = 0; i < buffer->numTriangles; i++ )
    {
        if( textlist->getItem(buffer->triangles[i].textureNumber) )
        {
            ((WLTexture*)(textlist->getItem(buffer->triangles[i].textureNumber )))->enable();
        }
        glBegin(GL_TRIANGLES );

        for ( int j = 0; j < 3; j++ )
        {
            glTexCoord2f(buffer->triangles[i].vertex[j].textCoord.x, 
                         buffer->triangles[i].vertex[j].textCoord.y );
            glVertex3f( buffer->triangles[i].vertex[j].point.x,
                       buffer->triangles[i].vertex[j].point.y,
                       buffer->triangles[i].vertex[j].point.z );
        }
        glEnd();

    }

    glPolygonMode(GL_BACK, GL_LINE);
}



