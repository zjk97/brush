/**
 * @file   QuadraticBrush.cpp
 *
 * Implementation of a brush with a quadratic mask distribution.
 *
 * You should fill this file in while completing the Brush assignment.
 */

#include "QuadraticBrush.h"

#include <math.h>

QuadraticBrush::QuadraticBrush(RGBA color, int radius)
    : Brush(color, radius)
{
    // @TODO: [BRUSH] You'll probably want to set up the mask right away.
    makeMask();
}

QuadraticBrush::~QuadraticBrush()
{
}

/**
 * this function calculates the mask for quadratic brush
 * by calculating distance from the center of the mask
 */
void QuadraticBrush::makeMask() {
    // @TODO: [BRUSH] Set up the mask for your Quadratic brush here...
    int d = m_radius*2 + 1;
    for(int x=0; x<d; x++){
        for(int y=0; y<d; y++){
            float dis = distance(x, y, m_radius);
            if(dis <= m_radius)
                m_mask.push_back(pow(1.0f-dis/m_radius, 2));
            else {
                m_mask.push_back(0.0f);
            }
        }//inner loop
    }//outer loop

}


