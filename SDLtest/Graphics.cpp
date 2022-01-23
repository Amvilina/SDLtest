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
    std::cout<<"des\n";
    SDL_DestroyRenderer(renderer);
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

void Graphics::Test(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
    SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
    SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
    
    SDL_SetRenderDrawColor(renderer, 205, 0, 155, 255);
    double dx, dy,cx,cy,r;
    cx = cy = 200;
    r = 100;
       dx = floor(sqrt((2.0 * r ) ));
       SDL_RenderDrawLine(renderer, cx-dx, cy+r, cx+dx, cy+r);
       SDL_RenderDrawLine(renderer, cx-dx, cy-r, cx+dx, cy-r);
       for (dy = 1; dy <= r; dy += 1.0) {
            dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
            SDL_RenderDrawPoint(renderer, cx+dx, cy+r-dy);
            SDL_RenderDrawPoint(renderer, cx+dx, cy-r+dy);
            SDL_RenderDrawPoint(renderer, cx-dx, cy+r-dy);
            SDL_RenderDrawPoint(renderer, cx-dx, cy-r+dy);
       }
}
