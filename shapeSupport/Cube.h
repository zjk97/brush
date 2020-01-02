#ifndef CUBE_H
#define CUBE_H
#include "OpenGLShape.h"

class Cube
        : public OpenGLShape
{
public:
    Cube(int p1, int p2, int p3);
    virtual ~Cube();
protected:
    virtual void calculateVertices();
    /**
    std::vector<std::vector<float>> faces = {
        {-0.5, 0.5, 0.5},
        {0.5, 0.5, },
        {},
        {},
        {},
        {}
    };
    **/
};

#endif // CUBE_H
