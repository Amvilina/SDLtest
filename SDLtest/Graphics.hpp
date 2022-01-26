#pragma once
#include <SDL.h>
#include <iostream>
#include "Color.hpp"
class Graphics{
public:
    Graphics();
    bool Initialize(SDL_Window *window);
    ~Graphics();
    
    void StartFrame();
    void EndFrame();
    
    void PutPixel(int x, int y, int R, int G, int B, int alpha = 255);
    void PutPixel(int x, int y, const Color& color);
    void PutPixel(int x, int y);
    
private:
    bool isInit;
    SDL_Renderer *renderer;
};
