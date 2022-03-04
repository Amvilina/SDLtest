#pragma once
#include <SDL.h>
#include <cassert>
#include <iostream>
#include "Color.hpp"
#include "Vec2_.hpp"
#include "Rect_.hpp"
#include "Surface.hpp"
#include "MainWindow.hpp"

class Graphics{
public:
    Graphics(const MainWindow& window);
    Graphics(const Graphics& other) = delete;
    Graphics& operator=(const Graphics& other) = delete;
    bool Initialize();
    ~Graphics();
public:
    void StartFrame();
    void EndFrame();
public:
    void PutPixel(int x, int y, const Color& color);
    void PutPixel(int x, int y, int R, int G, int B, int alpha = 255);
    Color GetPixel(int x, int y) const;
public:
    void DrawRect(const RectI& rect, const Color& color);
    void DrawRect(int x0, int y0, int x1, int y1, const Color& color);
    void DrawRect(const Vei2& point1, const Vei2& point2, const Color& color);
    void DrawRectDim(int x, int y, int width, int height, const Color& color);
    void DrawRectDim(const Vei2& pos, int width, int height, const Color& color);
public:
    void DrawCircle(int x0, int y0, int radius, const Color& color);
    void DrawCircle(const Vei2& center, int radius, const Color& color);
public:
    template <class SpecialEffect>
    void DrawSurface(int x, int y, const Surface& srf, SpecialEffect effect)
    {
        DrawSurface(x, y, srf, srf.GetRect(), effect);
    }
    template <class SpecialEffect>
    void DrawSurface(int x, int y, const Surface& srf, const RectI& srcRect, SpecialEffect effect)
    {
        DrawSurface(x, y, srf, srcRect, GetRect(), effect);
    }
    template <class SpecialEffect>
    void DrawSurface(int x, int y, const Surface& srf, RectI srcRect, const RectI& clip, SpecialEffect effect)
    {
        assert(srcRect.Left() >= 0);
        assert(srcRect.Right() <= srf.GetWidth() - 1);
        assert(srcRect.Top() >= 0);
        assert(srcRect.Bottom() <= srf.GetHeight() - 1);
        
        if(x < clip.Left()){
            srcRect.pos.x += clip.Left() - x;
            srcRect.width -= clip.Left() - x;
            x = clip.Left();
        }
        if(y < clip.Top()){
            srcRect.pos.y += clip.Top() - y;
            srcRect.height -= clip.Top() - y;
            y = clip.Top();
        }
        if(x + srcRect.width > clip.Right()){
            srcRect.width = clip.Right() - x + 1;
        }
        if(y + srcRect.height > clip.Bottom()){
            srcRect.height = clip.Bottom() - y + 1;
        }
        
        for (int sy = srcRect.Top(); sy <= srcRect.Bottom(); ++sy)
            for (int sx = srcRect.Left(); sx <= srcRect.Right(); ++sx){
                Color srfC = srf.GetPixel(sx, sy);
                int xDest = x + sx - srcRect.Left();
                int yDest = y + sy - srcRect.Top();
                effect(*this, xDest, yDest, srfC );
            }
    }
public:
    RectI GetRect() const;
    int GetWidth() const;
    int GetHeight() const;
private:
    bool isInit;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 * pixels;
    
    const MainWindow& window;
};
