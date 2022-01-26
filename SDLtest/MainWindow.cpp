#include "MainWindow.hpp"

MainWindow::MainWindow():isInit(false){}

bool MainWindow::Initialize(const char* title, int xpos, int ypos, int width, int height){
    if (!isInit) {
        isInit = true;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
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
    int w,h;
    SDL_GetWindowSize(window, &w, &h);
    return w;
}

int MainWindow::GetHeight() const{
    int w,h;
    SDL_GetWindowSize(window, &w, &h);
    return h;
}
