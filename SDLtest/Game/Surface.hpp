#pragma once
#include "Color.hpp"
#include <fstream>
#include <iostream>

class Surface{
public:
    Surface(int width, int height);
    ~Surface();
    Surface(const Surface& other);
    Surface& operator=(const Surface& other);
public:
    void PutPixel(int x, int y, Color c);
    Color GetPixel(int x, int y) const;
    int GetWidth() const;
    int GetHeight() const;
private:
    Color* pPixels = nullptr;
    int width;
    int height;
};
