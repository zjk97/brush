/**
 * @file   Brush.cpp
 *
 * Implementation of a brush that smudges the image on the canvas as the mouse is dragged.
 *
 * You should fill this file in for the Brush assignment.
 */

#include "SmudgeBrush.h"

#include "Canvas2D.h"

#include <iostream>
#include <cmath>

/**
 * This constructor initializes two member variables and calls makeMask through inheritence
 * */
SmudgeBrush::SmudgeBrush(RGBA color, int radius) :
    QuadraticBrush(color, radius),
    //initialize a vector with diameter*diameter size of empty RBGA structs
    m_brushDiameter(radius*2+1),
    m_buffer(m_brushDiameter*m_brushDiameter, RGBA(0, 0, 0, 255))
{
    // @TODO: [BRUSH] Initialize any memory you are going to use here. Hint - you are going to
    //       need to store temporary image data in memory. Remember to use automatically managed memory!
    QuadraticBrush::makeMask();

}


SmudgeBrush::~SmudgeBrush()
{
    // @TODO: [BRUSH] Be sure not to leak memory!  If you're using automatic memory management everywhere,
    //       this will be empty.
}


void SmudgeBrush::brushUp(int x, int y, Canvas2D* canvas) {
}


//! create a mask with a distribution of your choice (probably want to use quadratic for best results)
void SmudgeBrush::makeMask() {
    // @TODO: [BRUSH] Set up the mask for your brush here. For this brush you will probably want
    //        to use a quadratic distribution for the best results. Linear or Gaussian would
    //        work too, however. Feel free to paste your code from the Linear or Quadratic brushes
    //        or modify the class inheritance to be able to take advantage of one of those class's
    //        existing implementations. The choice is yours!
    //
}

void SmudgeBrush::brushDown(int x, int y, Canvas2D *canvas) {
    pickUpPaint(x, y, canvas);
}


//! Picks up paint from the canvas before drawing begins.
/**
 * This function picks up paint by first reseting the buffer and populating the buffer with the pixel info of
 * the area covered by the brush
 * @param x- mouseX
 * @param y- mouseY
 * @param canvas
 */
void SmudgeBrush::pickUpPaint(int x, int y, Canvas2D* canvas) {
    int width = canvas->width();
    int height = canvas->height();

    // @TODO: [BRUSH] Perform the "pick up paint" step described in the assignment handout here.
    //        In other words, you should store the "paint" under the brush mask in a temporary
    //        buffer (which you'll also have to figure out where and how to allocate). Then,
    //        in the paintOnce() method, you'll paste down the paint that you picked up here.
    //

    //reset buffer
    m_buffer.resize(m_brushDiameter*m_brushDiameter, RGBA(0, 0, 0, 255));
    RGBA *pix = canvas->data();

    int rowstart = std::max(0, y-m_radius);
    int rowend = std::min(height, y+m_radius+1);
    int colstart = std::max(0, x-m_radius);
    int colend =  std::min(width, x+m_radius+1);

    //store new paint in buffer
    for (int row = rowstart; row < rowend; row++) {
        for(int col = colstart; col<colend; col++) {
            m_buffer[(row-y+m_radius)*m_brushDiameter+col-x+m_radius] = pix[row*width+col];
        }
    }//outer loop
    //std::cout << "paint picked up, buffer size: " << m_buffer.size() << std::endl;
}

/**
 * This function implements SmudgeBrush's brushDragged function
 * This function paints the area covered by brush by mixing the paint on the brush and the canvas paint
 * Then this function will pick up paint again by calling pickUpPaint()
 * @param mouseX
 * @param mouseY
 * @param canvas
 */
void SmudgeBrush::brushDragged(int mouseX, int mouseY, Canvas2D* canvas) {
    // @TODO: [BRUSH] Here, you'll need to paste down the paint you picked up in
    //        the previous method. Be sure to take the mask into account! You can
    //        ignore the alpha parameter, but you can also use it (smartly) if you
    //        would like to.

    int w = canvas->width();
    RGBA *pix = canvas->data();

    int rowstart = std::max(0, mouseY-m_radius);
    int rowend = std::min(canvas->height(), mouseY+m_radius+1);
    int colstart = std::max(0, mouseX-m_radius);
    int colend =  std::min(w, mouseX+m_radius+1);

    for (int row = rowstart; row < rowend; row++) {
        for(int col = colstart; col<colend; col++){
            unsigned long currentBuffer = (row-mouseY+m_radius)*m_brushDiameter+col-mouseX+m_radius;

            int br = m_buffer[currentBuffer].r;
            int bg = m_buffer[currentBuffer].g;
            int bb = m_buffer[currentBuffer].b;
            float ba = m_buffer[currentBuffer].a/255.f;

            float m = m_mask[currentBuffer];
            //std::cout << (row-mouseY+m_radius)*brushDiameter+col-mouseX+m_radius << std::endl;

            int currentPixel = row*w+col;

            pix[currentPixel] = RGBA(m*ba*br+(1-m*ba)*pix[currentPixel].r,
                                     m*ba*bg+(1-m*ba)*pix[currentPixel].g,
                                     m*ba*bb+(1-m*ba)*pix[currentPixel].b,
                                     255);
            //RGBA(m*ba*br+(1-m*ba)*cr, m*ba*bg+(1-m*ba)*cg, m*ba*bb+(1-m*ba)*cb, 255);

        }
    }
    canvas->update();


    // now pick up paint again...
    pickUpPaint(mouseX, mouseY, canvas);

}
/*
 * 1. create a vector buffer, size: diameter*diameter
 * 2. set every element to default RBGA(0, 0, 0, 0)
 * 3. find relative position on buffer like finding relative position in mask and store the RBGA value
 * */

