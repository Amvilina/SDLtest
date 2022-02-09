#include "Board.hpp"
namespace SnakeGame{

Board::Board(Graphics& gfx):gfx(gfx){
    
}


void Board::DrawCell(int x, int y, const Color &color){
    const int left = marginX + borderWidth + x*dimension + padding;
    const int top = marginY + borderWidth + y*dimension + padding;
    
    gfx.DrawRectDim(iVec2(left,top), dimension-2, dimension-2, color);
}

void Board::DrawCell(const iVec2 &pos, const Color &color){
    DrawCell(pos.x, pos.y, color);
}

void Board::DrawBoard(){
    for (int i = 0; i<width; ++i)
        for(int j = 0;j<height;++j)
            DrawCell(i, j, boardColor);
    
}

void Board::DrawBorder(){
    
    const int left = marginX;
    const int top = marginY;
    const int right = left + 2*borderWidth + width*dimension;
    const int bottom = top + 2*borderWidth + height*dimension;
    
    //top
    gfx.DrawRect(left, top, right, top+borderWidth, borderColor);
    
    //left
    gfx.DrawRect(left, top, left+borderWidth, bottom, borderColor);
    
    //bottom
    gfx.DrawRect(left, bottom-borderWidth, right, bottom, borderColor);
    
    //right
    gfx.DrawRect(right-borderWidth, top, right, bottom, borderColor);
    
    
}

//constexpr int Board::GetWidth(){
//    return width;
//}
//
//constexpr int Board::GetHeight(){
//    return height;
//}


}