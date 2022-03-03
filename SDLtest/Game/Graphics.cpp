#include "Graphics.hpp"

Graphics::Graphics(const MainWindow& window):isInit(false), window(window){}

bool Graphics::Initialize(){
    if (!isInit) {
        isInit = true;
        
        renderer = SDL_CreateRenderer(window.GetSDLWindow(), -1, 0);
        
        texture = SDL_CreateTexture(renderer,
            SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, window.GetWidth(), window.GetHeight());
        
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

void Graphics::PutPixel(int x, int y, const Color &color){
    assert(x>=0);
    assert(y>=0);
    assert(x<=window.GetWidth()-1);
    assert(y<=window.GetHeight()-1);
    pixels[window.GetWidth()*y + x] = color.value;
}

void Graphics::PutPixel(int x, int y, int R, int G, int B, int alpha){
    Color color(R,G,B,alpha);
    PutPixel(x, y, color);
}

Color Graphics::GetPixel(int x, int y) const{
    return pixels[window.GetWidth()*y + x];
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

void Graphics::DrawCircle(int x0, int y0, int radius, const Color& color){
    for (int x = x0 - radius; x<=x0+radius; ++x)
        for (int y = y0 - radius; y<=y0+radius; ++y){
            const int x_dist = x-x0;
            const int y_dist = y-y0;
            if(x_dist*x_dist + y_dist*y_dist <= radius*radius)
                PutPixel(x, y, color);
        }
}

void Graphics::DrawCircle(const iVec2& center, int radius, const Color& color){
    DrawCircle(center.x, center.y, radius, color);
}

void Graphics::DrawSurfaceNonChroma(int x, int y, const Surface &srf){
    DrawSurfaceNonChroma(x, y, srf, srf.GetRect());
}

void Graphics::DrawSurfaceNonChroma(int x, int y, const Surface& srf, const Rect& srcRect){
    DrawSurfaceNonChroma(x, y, srf, srcRect, GetRect());
}
 
void Graphics::DrawSurfaceNonChroma(int x, int y, const Surface& srf, Rect srcRect, const Rect& clip){
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
        for (int sx = srcRect.Left(); sx <= srcRect.Right(); ++sx)
            PutPixel( x + sx - srcRect.Left(), y + sy - srcRect.Top(), srf.GetPixel(sx, sy));
}

void Graphics::DrawSurface(int x, int y, const Surface& srf, const Color& chromoColor){
    DrawSurface(x, y, srf, srf.GetRect(), chromoColor);
}

void Graphics::DrawSurface(int x, int y, const Surface& srf, const Rect& srcRect, const Color& chromoColor){
    DrawSurface(x, y, srf, srcRect, GetRect(), chromoColor);
}

void Graphics::DrawSurface(int x, int y, const Surface& srf, Rect srcRect, const Rect& clip, const Color& chromoColor){
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
            if(srfC == chromoColor)
                continue;
            PutPixel( x + sx - srcRect.Left(), y + sy - srcRect.Top(), srfC);
        }
}

void Graphics::DrawSurfaceSubstitute(int x, int y, const Surface& srf, const Color& chromoColor, const Color& substituteColor){
    DrawSurface(x, y, srf, srf.GetRect(), substituteColor);
}

void Graphics::DrawSurfaceSubstitute(int x, int y, const Surface& srf, const Rect& srcRect, const Color& chromoColor, const Color& substituteColor){
    DrawSurfaceSubstitute(x, y, srf, srcRect, GetRect(), chromoColor, substituteColor);
}

void Graphics::DrawSurfaceSubstitute(int x, int y, const Surface& srf, Rect srcRect, const Rect& clip, const Color& chromoColor,
                                     const Color& substituteColor)
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
            if(srfC == chromoColor)
                continue;
            PutPixel( x + sx - srcRect.Left(), y + sy - srcRect.Top(), substituteColor);
        }
}

void Graphics::DrawSurfaceGhost(int x, int y, const Surface& srf, const Color& chromoColor, double ratio){
    DrawSurfaceGhost(x, y, srf, srf.GetRect(), chromoColor, ratio);
}

void Graphics::DrawSurfaceGhost(int x, int y, const Surface& srf, const Rect& srcRect, const Color& chromoColor, double ratio){
    DrawSurfaceGhost(x, y, srf, srcRect, GetRect(), chromoColor, ratio);
}

void Graphics::DrawSurfaceGhost(int x, int y, const Surface& srf, Rect srcRect, const Rect& clip, const Color& chromoColor, double ratio){
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
            Color backC = GetPixel(x + sx - srcRect.Left() , y + sy - srcRect.Top());
            if(srfC == chromoColor)
                continue;
            Color newC = Color(
                               backC.GetR() * (1-ratio) + srfC.GetR() * ratio,
                               backC.GetG() * (1-ratio) + srfC.GetG() * ratio,
                               backC.GetB() * (1-ratio) + srfC.GetB() * ratio
                               );
            PutPixel( x + sx - srcRect.Left(), y + sy - srcRect.Top(), newC);
        }
}



Rect Graphics::GetRect() const{
    return Rect(0, 0, window.GetWidth(), window.GetHeight());
}

int Graphics::GetWidth() const{
    return window.GetWidth();
}

int Graphics::GetHeight() const{
    return window.GetHeight();
}
