/**
 * @file   ConstantBrush.cpp
 *
 * Implementation of a brush with a constant mask distribution.
 *
 * You should fill this file in while completing the Brush assignment.
 */

#include "ConstantBrush.h"
#include <iostream>

ConstantBrush::ConstantBrush(RGBA color, int radius)
    : Brush(color, radius)
{
    // @TODO: [BRUSH] You'll probably want to set up the mask right away.
    makeMask();
}


ConstantBrush::~ConstantBrush()
{
}

/**
 * this function calculates the mask for constant brush
 * by calculating distance from the center of the mask
 */
void ConstantBrush::makeMask() {
    // @TODO: [BRUSH] Set up the mask for your Constant brush here...
    int d = m_radius*2 + 1;
    for(int x=0; x<d; x++){
        for(int y=0; y<d; y++){
            if(distance(x, y, m_radius) <= m_radius)
                m_mask.push_back(1.0f);
            else {
                m_mask.push_back(0.0f);
            }
        }//inner loop
    }//outer loop


/*
    for(float x : m_mask)
        std::cout << x;
        */

}


/*
 * r=2
 * center: 2, 2
 * distance from center = root[(r-i)^2 + (r-j)^2]
 *
*/
