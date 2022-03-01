#include "Surface.hpp"
#include <cassert>

Surface::Surface(int width, int height)
    :
    width(width),
    height(height),
    pPixels(new Color[width*height])
{}

Surface::~Surface(){
    delete [] pPixels;
}

Surface::Surface(const Surface& other)
{
    *this = other;
}

Surface& Surface::operator=(const Surface& other){
    delete [] pPixels;
    
    width = other.width;
    height = other.height;
    const int nPixels = width*height;
    pPixels = new Color[nPixels];
    for (int i = 0; i<nPixels; ++i) {
        pPixels[i] = other.pPixels[i];
    }
    
    return *this;
}

void Surface::PutPixel(int x, int y, Color c){
    assert(x >= 0);
    assert(x <= width-1);
    assert(y >= 0);
    assert(y <= height-1);
    pPixels[y*width + x] = c;
}

Color Surface::GetPixel(int x, int y) const{
    assert(x >= 0);
    assert(x <= width-1);
    assert(y >= 0);
    assert(y <= height-1);
    return pPixels[y*width + x];
}

int Surface::GetWidth() const{
    return width;
}

int Surface::GetHeight() const{
    return height;
}
