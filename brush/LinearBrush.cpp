/**
 * @file   LinearBrush.cpp
 *
 * Implementation of a brush with a linear mask distribution.
 *
 * You should fill this file in while completing the Brush assignment.
 */

#include "LinearBrush.h"

#include <math.h>
#include <iostream>

LinearBrush::LinearBrush(RGBA color, int radius)
    : Brush(color, radius)
{
    // @TODO: [BRUSH] You'll probably want to set up the mask right away.
    makeMask();
}


LinearBrush::~LinearBrush()
{
}

/**
 * this function calculates the mask for linear brush
 * by calculating distance from the center of the mask
 */
void LinearBrush::makeMask() {
    // @TODO: [BRUSH] Set up the mask for your Linear brush here...
    int d = m_radius*2 + 1;
    for(int x=0; x<d; x++){
        for(int y=0; y<d; y++){
            float dis = distance(x, y, m_radius);
            if(dis <= m_radius)
                m_mask.push_back(1.f-dis/m_radius);
            else {
                m_mask.push_back(0.0f);
            }
        }//inner loop
    }//outer loop

    /*
    for(float x : m_mask)
        std::cout << x << ", ";
        */
}


/*
 * 0    0   0   0    0
 * 0   .29  .5  .29  0
 * 0   .5   1   .5   0
 * 0   .29  .5  .29  0
 * 0    0   0   0    0
 * */
