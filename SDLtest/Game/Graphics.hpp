#pragma once
#include <SDL.h>
#include <cassert>
#include <iostream>
#include "Color.hpp"
#include "dVec2.hpp"
#include "Rect.hpp"
#include "Surface.hpp"

class Graphics{
public:
    Graphics(const MainWindow& window);
    bool Initialize();
    ~Graphics();
    
    void StartFrame();
    void EndFrame();
    
    void PutPixel(int x, int y, const Color& color);
    void PutPixel(int x, int y, int R, int G, int B, int alpha = 255);
    
    void DrawRect(int x0, int y0, int x1, int y1, const Color& color);
    void DrawRect(const iVec2& point1, const iVec2& point2, const Color& color);
    void DrawRectDim(int x, int y, int width, int height, const Color& color);
    void DrawRectDim(const iVec2& pos, int width, int height, const Color& color);
    void DrawRect(const Rect& rect, const Color& color);
    
    void DrawCircle(int x0, int y0, int radius, const Color& color);
    void DrawCircle(const iVec2& center, int radius, const Color& color);
    
    void DrawSurface(int x, int y, const Surface& srf);
    void DrawSurface(int x, int y, const Surface& srf, const Rect& srcRect);
    void DrawSurface(int x, int y, const Surface& srf, Rect srcRect, const Rect& clip);
    
    Rect GetRect() const;
    
    int GetWidth() const;
    int GetHeight() const;
private:
    bool isInit;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 * pixels;
    
    const MainWindow& window;
};
