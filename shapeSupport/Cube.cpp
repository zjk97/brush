#include "Cube.h"
#include <iostream>

Cube::Cube(int p1, int p2, int p3):
    OpenGLShape (p1, p2, p3)
{
    calculateVertices();
    //std::cout << "working" << std::endl;
}

Cube::~Cube()
{
}

void Cube::calculateVertices(){

 //face1-------------------------------------
    float unitLength = 1.f/m_p1;

    float vx = -0.5;
    float vy = 0.5;
    float vz = 0.5;

    for(int row=0; row<m_p1; row++){
        for(int col=0; col<=m_p1; col++){
            //top vertice
            m_vertices.insert(m_vertices.end(), {
                                  //top vertice
                                  vx + col*unitLength,//x
                                  vy - row*unitLength,//y
                                  vz, //z
                                  0.f,
                                  0.f,
                                  1.f,

                                  //bottom vertice
                                  vx + col*unitLength,
                                  vy - (row+1)*unitLength,
                                  vz,
                                  0.f,
                                  0.f,
                                  1.f
                              });
        }//inner loop
        //create degenerate triangles
        if(row+1<m_p1){
            m_vertices.insert(m_vertices.end(), {vx + m_p1*unitLength,
                                                 vy - (row+1)*unitLength,
                                                 vz,
                                                 0.f,
                                                 0.f,
                                                 1.f,
                                                 vx + 0*unitLength,
                                                 vy - (row+1)*unitLength,
                                                 vz,
                                                 0.f,
                                                 0.f,
                                                 1.f});
        }
    }//outer loop

//face2----------------------------------
    vx = 0.5;
    vy = 0.5;
    vz = 0.5;

    for(int row=0; row<m_p1; row++){
        for(int col=0; col<=m_p1; col++){
            m_vertices.insert(m_vertices.end(), {
                                  //top vertice
                                  vx,
                                  vy - row*unitLength,
                                  vz - col*unitLength,
                                  1.f,
                                  0.f,
                                  0.f,

                                  //bottom vertice
                                  vx,
                                  vy - (row+1)*unitLength,
                                  vz - col*unitLength,
                                  1.f,
                                  0.f,
                                  0.f
                              });
        }//inner loop
        //create degenerate triangles
        if(row+1<m_p1){
            m_vertices.insert(m_vertices.end(), {vx,
                                                 vy - (row+1)*unitLength,
                                                 vz - m_p1*unitLength,
                                                 1.f,
                                                 0.f,
                                                 0.f,
                                                vx,
                                                vy - (row+1)*unitLength,
                                                vz - 0*unitLength,
                                                1.f,
                                                0.f,
                                                0.f});
        }
    }//outer loop

 //face3----------------------------------
    vx = 0.5;
    vy = 0.5;
    vz = -0.5;

    for(int row=0; row<m_p1; row++){
        for(int col=0; col<=m_p1; col++){
            m_vertices.insert(m_vertices.end(), {
                                  //top vertice
                                  vx - col*unitLength,
                                  vy - row*unitLength,
                                  vz,
                                  0.f,
                                  0.f,
                                  -1.f,

                                  //bottom vertice
                                  vx - col*unitLength,
                                  vy - (row+1)*unitLength,
                                  vz,
                                  0.f,
                                  0.f,
                                  -1.f
                              });
        }//inner loop
        //create degenerate triangles
        if(row+1<m_p1){
           m_vertices.insert(m_vertices.end(), {vx - m_p1*unitLength, vy - (row+1)*unitLength, vz, 0.f, 0.f, -1.f});
           m_vertices.insert(m_vertices.end(), {vx - 0*unitLength, vy - (row+1)*unitLength, vz, 0.f, 0.f, -1.f,
                             });
           std::cout << "iran" << std::endl;
        }
    }//outer loop


    //face4----------------------------------
    vx = -0.5;
    vy = 0.5;
    vz = -0.5;

    for(int row=0; row<m_p1; row++){
        for(int col=0; col<=m_p1; col++){
            m_vertices.insert(m_vertices.end(), {
                                  //top vertice
                                  vx + col*unitLength,
                                  vy,
                                  vz + row*unitLength,
                                  0.f,
                                  1.f,
                                  0.f,

                                  //bottom vertice
                                  vx + col*unitLength,
                                  vy,
                                  vz + (row+1)*unitLength,
                                  0.f,
                                  1.f,
                                  0.f
                              });
        }//inner loop
        //create degenerate triangles
        if(row+1<m_p1){
            m_vertices.insert(m_vertices.end(), {vx + m_p1*unitLength, vy, vz + (row+1)*unitLength, 0.f, 1.f, 0.f});
           m_vertices.insert(m_vertices.end(), {vx + 0*unitLength, vy, vz +(row+1)*unitLength, 0.f, -1.f, 0.f});
        }
    }//outer loop


    //face5----------------------------------
    vx = -0.5;
    vy = 0.5;
    vz = -0.5f;

    for(int row=0; row<m_p1; row++){
        for(int col=0; col<=m_p1; col++){
            m_vertices.insert(m_vertices.end(), {
                                  //top vertice
                                  vx,
                                  vy - row*unitLength,
                                  vz + col*unitLength,
                                  -1.f,
                                  0.f,
                                  0.f,

                                  //bottom vertice
                                  vx,
                                  vy - (row+1)*unitLength,
                                  vz + col*unitLength,
                                  -1.f,
                                  0.f,
                                  0.f
                              });
        }//inner loop
        //create degenerate triangles
        if(row+1<m_p1){
            m_vertices.insert(m_vertices.end(), {vx, vy - (row+1)*unitLength, vz + m_p1*unitLength, -1.f, 0.f, 0.f});
            m_vertices.insert(m_vertices.end(), {vx, vy - (row+1)*unitLength, vz + 0*unitLength, -1.f, 0.f, 0.f});
        }
    }//outer loop


    //face6----------------------------------
    vx = -0.5;
    vy = -0.5;
    vz = 0.5f;

    for(int row=0; row<m_p1; row++){
        for(int col=0; col<=m_p1; col++){
            m_vertices.insert(m_vertices.end(), {
                                  //top vertice
                                  vx + col*unitLength,
                                  vy,
                                  vz - row*unitLength,
                                  0.f,
                                  -1.f,
                                  0.f,

                                  //bottom vertice
                                  vx + col*unitLength,
                                  vy,
                                  vz - (row+1)*unitLength,
                                  0.f,
                                  -1.f,
                                  0.f
                              });
        }//inner loop
        //create degenerate triangles
        if(row+1<m_p1){
            m_vertices.insert(m_vertices.end(), {vx + m_p1*unitLength, vy, vz - (row+1)*unitLength, 0.f, -1.f, 0.f});
           m_vertices.insert(m_vertices.end(), {vx + 0*unitLength, vy, vz - (row+1)*unitLength, 0.f, -1.f, 0.f});
        }
    }//outer loop


}//end of calculateVertices
