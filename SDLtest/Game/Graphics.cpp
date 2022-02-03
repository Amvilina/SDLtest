#include "Graphics.hpp"

Graphics::Graphics():isInit(false){}

bool Graphics::Initialize(SDL_Window *window){
    if (!isInit) {
        isInit = true;
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        return  renderer;
        
    }
    return false;
}

Graphics::~Graphics(){
    SDL_DestroyRenderer(renderer);
    std::cout<<"Renderer destroyed!\n";
}

void Graphics::StartFrame(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Graphics::EndFrame(){
    SDL_RenderPresent(renderer);
}

void Graphics::SetColor(int R, int G, int B, int alpha){
    SDL_SetRenderDrawColor(renderer, R, G, B, alpha);
}

void Graphics::SetColor(const Color &color){
    SDL_SetRenderDrawColor(renderer, color.GetR(), color.GetG(), color.GetB(), color.GetA());
}

void Graphics::PutPixel(int x, int y, int R, int G, int B, int alpha){
    SDL_SetRenderDrawColor(renderer, R, G, B, alpha);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::PutPixel(int x, int y, const Color &color){
    SDL_SetRenderDrawColor(renderer, color.GetR(), color.GetG(), color.GetB(), color.GetA());
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::PutPixel(int x, int y){
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::DrawRect(int x0, int y0, int x1, int y1, const Color& color){
    if(x0>x1)
        std::swap(x0, x1);
    if(y0>y1)
        std::swap(y0, y1);
    
    SetColor(color);
    
    for (int i = x0; i<x1; ++i)
        for(int j = y0; j<y1; ++j)
            PutPixel(i, j);
            
}

void Graphics::DrawRect(const Vec2& pos, int width, int height, const Color& color){
    DrawRect(pos.x, pos.y, pos.x+width, pos.y+height, color);
}

void Graphics::DrawRect(const Vec2& pos, const Vec2& size, const Color& color){
    DrawRect(pos, size.x, size.y, color);
}

void Graphics::DrawRect(const Rect &rect, const Color &color){
    DrawRect(rect.pos, rect.size, color);
}

