#pragma once
#include "Graphics.hpp"
#include "Color.hpp"


namespace SnakeGame{

class Board{
public:
    Board(Graphics& gfx);
    
    void DrawCell(int x, int y, const Color& color);
    void DrawCell(const iVec2& pos, const Color& color);
    void DrawCellCircle(int x, int y, const Color& color);
    void DrawCellCircle(const iVec2& pos, const Color& color);
    void DrawBoard();
    void DrawBorder();
    
    static constexpr int GetWidth(){return width;}
    static constexpr int GetHeight(){return height;}
    
private:
    
    static constexpr int dimension = 21;
    static constexpr int padding = 1;
    static constexpr int width = 34;
    static constexpr int height = 28;
    static constexpr int borderWidth = 5;
    static constexpr int marginX = 38;
    static constexpr int marginY = 1;
    
    static constexpr Color borderColor = Color(0x1E7E9C);
    static constexpr Color boardColor = Color(0x474747);
    
    Graphics& gfx;
};


}
