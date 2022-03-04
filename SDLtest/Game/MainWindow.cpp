#include "MainWindow.hpp"

MainWindow::MainWindow():isInit(false){}

bool MainWindow::Initialize(const char* title, int xpos, int ypos, int width, int height){
    if (!isInit) {
        isInit = true;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        
        this->width = width;
        this->height = height;
        
        return  window;
        
    }
    return false;
}

MainWindow::~MainWindow(){
    SDL_DestroyWindow(window);
    std::cout<<"Window destroyed!\n";
}

SDL_Window* MainWindow::GetSDLWindow() const{
    return window;
}

int MainWindow::GetWidth() const{
//    int w,h;
//    SDL_GetWindowSize(window, &w, &h);
//    return w;
    return width;
}

int MainWindow::GetHeight() const{
//    int w,h;
//    SDL_GetWindowSize(window, &w, &h);
//    return h;
    return height;
}

RectI MainWindow::GetRect() const{
    return RectI { Vei2{ 0, 0 }, GetWidth(), GetHeight()};
}
