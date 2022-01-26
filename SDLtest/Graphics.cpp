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

