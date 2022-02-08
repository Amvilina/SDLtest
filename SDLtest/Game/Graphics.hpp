#pragma once
#include <SDL.h>
#include <iostream>
#include "Color.hpp"
#include "Vec2.hpp"
#include "Rect.hpp"

class Graphics{
public:
    Graphics(const MainWindow& window);
    bool Initialize();
    ~Graphics();
    
    void StartFrame();
    void EndFrame();
    
    void PutPixel(int x, int y, int R, int G, int B, int alpha = 255);
    void PutPixel(int x, int y, const Color& color);
    
    void DrawRect(int x0, int y0, int x1, int y1, const Color& color);
    void DrawRect(const Vec2& pos, int width, int height, const Color& color);
    void DrawRect(const Vec2& pos, const Vec2& size, const Color& color);
    void DrawRect(const Rect& rect, const Color& color);
    
private:
    bool isInit;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 * pixels;
    
    const MainWindow& window;
};
