#include "Graphics.hpp"

Graphics::Graphics(const MainWindow& window):isInit(false), window(window){}

bool Graphics::Initialize(){
    if (!isInit) {
        isInit = true;
        
        renderer = SDL_CreateRenderer(window.GetSDLWindow(), -1, 0);
        
        texture = SDL_CreateTexture(renderer,
            SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, window.GetWidth(), window.GetHeight());
        
        pixels = new Uint32[window.GetWidth() * window.GetHeight()];
        memset(pixels, 255, window.GetWidth() * window.GetHeight() * sizeof(Uint32));
        
        return  renderer;
        
    }
    return false;
}

Graphics::~Graphics(){
    SDL_DestroyRenderer(renderer);
    std::cout<<"Renderer destroyed!\n";
}

void Graphics::StartFrame(){
    SDL_UpdateTexture(texture, NULL, pixels, window.GetWidth() * sizeof(Uint32));
    for (int i = 0; i<window.GetWidth()*window.GetHeight(); ++i)
        pixels[i] = 0;
}

void Graphics::EndFrame(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Graphics::PutPixel(int x, int y, int R, int G, int B, int alpha){
    Color color(R,G,B,alpha);
    PutPixel(x, y, color);
}

void Graphics::PutPixel(int x, int y, const Color &color){
    pixels[window.GetWidth()*y + x] = color.value;
}

void Graphics::DrawRect(int x0, int y0, int x1, int y1, const Color& color){
    if(x0>x1)
        std::swap(x0, x1);
    if(y0>y1)
        std::swap(y0, y1);
    

    
    for (int i = x0; i<x1; ++i)
        for(int j = y0; j<y1; ++j)
            PutPixel(i, j,color);
            
}

void Graphics::DrawRect(const iVec2& point1, const iVec2& point2, const Color& color){
    DrawRect(point1.x, point1.y, point2.x, point2.y, color);
}

void Graphics::DrawRectDim(int x, int y, int width, int height, const Color& color){
    DrawRect(x, y, x+width, y+height, color);
}

void Graphics::DrawRectDim(const iVec2& pos, int width, int height, const Color& color){
    DrawRectDim(pos.x, pos.y, width, height, color);
}

void Graphics::DrawRect(const Rect &rect, const Color &color){
    DrawRectDim(rect.pos.x, rect.pos.y, rect.width, rect.height, color);
}

