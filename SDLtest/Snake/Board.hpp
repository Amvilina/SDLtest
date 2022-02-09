#pragma once
#include "Graphics.hpp"
#include "Color.hpp"


namespace SnakeGame{

class Board{
public:
    Board(Graphics& gfx);
    
    void DrawCell(int x, int y, const Color& color);
    void DrawCell(const iVec2& pos, const Color& color);
    void DrawBoard();
    void DrawBorder();
    
    static constexpr int GetWidth(){return width;}
    static constexpr int GetHeight(){return height;}
    
private:
    
    static constexpr int dimension = 20;
    static constexpr int padding = 1;
    static constexpr int width = 33;
    static constexpr int height = 27;
    static constexpr int borderWidth = 5;
    static constexpr int marginX = 65;
    static constexpr int marginY = 25;
    
    Color borderColor = Color(100,200,200);
    Color boardColor = Color(100,10,10);
    
    Graphics& gfx;
};


}
