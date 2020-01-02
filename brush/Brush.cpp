/**
 * @file   Brush.cpp
 *
 * Implementation of common functionality of bitmap brushes.
 *
 * You should fill this file in while scompleting the Brush assignment.
 */

#include "Brush.h"
#include "Canvas2D.h"
#include <cmath>
#include <iostream>
//added by me
#include "Settings.h"
//------------------------------------------------------------------

static unsigned char lerp(unsigned char a, unsigned char b, float percent) {
    float fa = static_cast<float>(a) / 255.0f;
    float fb = static_cast<float>(b) / 255.0f;
    return static_cast<unsigned char>((fa + (fb - fa) * percent) * 255.0f + 0.5f);
}



Brush::Brush(RGBA color, int radius) :
    // Pro-tip: Initialize all variables in the initialization list
    m_color(color),
    m_mask(),
    m_radius(radius)
{
    // Pro-tip: By the time you get to the constructor body, all of the
    // member variables have already been initialized.
    setRGBA(color);
    setAlpha(color.a);
    setRed(color.r);
    setBlue(color.b);
    setGreen(color.g);
}


Brush::~Brush()
{
    // Pro-tip: The destructor (here) is where you free all the resources
    // you allocated during the lifetime of the class
    // Pro-tip: If you use std::unique_ptr or std::vector, you probabably
    // won't need to put anything in here.
}

int Brush::getAlpha() const {
    return m_color.a;
}

RGBA Brush::getRGBA() const {
    return m_color;
}

int Brush::getBlue() const {
    return m_color.b;
}

int Brush::getGreen() const {
    return m_color.g;
}

int Brush::getRadius() const {
    return m_radius;
}

int Brush::getRed() const {
    return m_color.r;
}

void Brush::setAlpha(int alpha) {
    m_color.a = alpha;
}

void Brush::setRGBA(const RGBA &rgba) {
    m_color = rgba;
}

void Brush::setBlue(int blue) {
    m_color.b = blue;
}

void Brush::setGreen(int green) {
    m_color.g = green;
}

void Brush::setRed(int red) {
    m_color.r = red;
}

void Brush::setRadius(int radius) {
    m_radius = radius;
    makeMask();
}

//added by me
/**
 * this function calculates the distance from the pixel clicked based on mouseX, mouseY, and radius
 * @param x- mouseX
 * @param y- mouseY
 * @param r- radius
 * @return distance from the pixel clicked to (x, y)
 */
float Brush::distance(int x, int y, int r){
    //calculate distance from center based on x, y coordinates and radius
    //distance from center = sqrt[(r-x)^2 + (r-y)^2]
    int h = pow((r-x), 2) + pow((r-y), 2);
    return sqrt(h);
}

/**
 * this function first calculates where to start painting and then paint each pixel
 * one row at a time
 * @param mouseX
 * @param mouseY
 * @param canvas
 */
void Brush::brushDragged(int mouseX, int mouseY, Canvas2D* canvas) {
    // @TODO: [BRUSH] You can do any painting on the canvas here. Or, you can
    //        override this method in a subclass and do the painting there.
    //
    // Example: You'll want to delete or comment out this code, which
    // sets all the pixels on the canvas to red.
    //

    /* ORIGNAL CODE: SETS THE CANVAS TO RED
    RGBA *pix = canvas->data();
    int size = canvas->width() * canvas->height();
    for (int i = 0; i < size; i++) {
        pix[i] = RGBA(255, 0, 0, 255);
    }
    canvas->update();
    */

    //added by me
    int w = canvas->width();

    RGBA *pix = canvas->data();

    int rowstart = std::max(0, mouseY-m_radius);
    int rowend = std::min(canvas->height(), mouseY+m_radius+1);
    int colstart = std::max(0, mouseX-m_radius);
    int colend =  std::min(w, mouseX+m_radius+1);


    int br = this->getRed();
    int bg = this->getGreen();
    int bb = this->getBlue();
    float ba = this->getAlpha()/255.f;
    int brushDiameter = m_radius*2 + 1;


    for (int row = rowstart; row < rowend; row++) {
        for(int col = colstart; col<colend; col++){
            float m = m_mask[(row-mouseY+m_radius)*brushDiameter+col-mouseX+m_radius];
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
    /*
    std::cout << "x: " << mouseX << std::endl;
    std::cout << "y: " << mouseY << std::endl;
    std::cout << "radius: " << m_radius << std::endl;
    */
    //-----------------------------------------------------------------------------
//-----------------------------------------------
}
