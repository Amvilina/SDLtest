#pragma once
#include <SDL.h>
#include <iostream>
#include "Color.hpp"
#include "Vec2.hpp"
#include "Rect.hpp"

class Graphics{
public:
    Graphics();
    bool Initialize(SDL_Window *window);
    ~Graphics();
    
    void StartFrame();
    void EndFrame();
    
    void SetColor(int R, int G, int B, int alpha = 255);
    void SetColor(const Color& color);
    
    void PutPixel(int x, int y, int R, int G, int B, int alpha = 255);
    void PutPixel(int x, int y, const Color& color);
    void PutPixel(int x, int y);
    
    void DrawRect(int x0, int y0, int x1, int y1, const Color& color);
    void DrawRect(const Vec2& pos, int width, int height, const Color& color);
    void DrawRect(const Vec2& pos, const Vec2& size, const Color& color);
    void DrawRect(const Rect& rect, const Color& color);
    
private:
    bool isInit;
    SDL_Renderer *renderer;
};
