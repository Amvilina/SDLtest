#pragma once
#include "Graphics.hpp"
#include "Color.hpp"
#include "Point.hpp"

namespace SnakeGame{

class Board{
public:
    Board(Graphics& gfx);
    
    void DrawCell(int x, int y, const Color& color);
    void DrawCell(const Point& pos, const Color& color);
    void DrawBoard();
    void DrawBorder();
    
    static int GetWidth();
    static int GetHeight();
    
private:
    
    static constexpr int dimension = 30;
    static constexpr int padding = 1;
    static constexpr int width = 22;
    static constexpr int height = 18;
    static constexpr int borderWidth = 5;
    static constexpr int marginX = 65;
    static constexpr int marginY = 25;
    
    Color borderColor = Color(100,200,200);
    Color boardColor = Color(100,10,10);
    
    Graphics& gfx;
};


}
