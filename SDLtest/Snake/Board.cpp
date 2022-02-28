#include "Board.hpp"
#include "Snake.hpp"
#include "Random.hpp"
namespace SnakeGame{

Board::Board(Graphics& gfx):gfx(gfx){
    pBoard = new TileType[width*height];
}

Board::~Board(){
    delete[] pBoard;
}

void Board::DrawCell(int x, int y, const Color &color){
    const int left = marginX + borderWidth + x*dimension + padding;
    const int top = marginY + borderWidth + y*dimension + padding;
    
    gfx.DrawRectDim(iVec2(left,top), dimension-2, dimension-2, color);
}

void Board::DrawCell(const iVec2 &pos, const Color &color){
    DrawCell(pos.x, pos.y, color);
}

void Board::DrawCellCircle(int x, int y, const Color& color){
    const int x_center = marginX + borderWidth + x*dimension + padding + dimension/2 -1;
    const int y_center = marginY + borderWidth + y*dimension + padding + dimension/2 -1;
    
    gfx.DrawCircle(x_center, y_center, dimension/2-1, color);
}

void Board::DrawCellCircle(const iVec2& pos, const Color& color){
    DrawCellCircle(pos.x, pos.y, color);
}

void Board::DrawBoard(){
    for (int i = 0; i<width; ++i)
        for(int j = 0;j<height;++j){
            TileType tile = pBoard[j*width + i];
            switch (tile) {
                case TileType::None:
                    DrawCell(i, j, boardColor);
                    break;
                case TileType::Apple:
                    DrawCell(i, j, appleColor);
                    break;
                case TileType::Obstacle:
                    DrawCell(i, j, obstacleColor);
                    break;
                case TileType::Poison:
                    DrawCell(i, j, poisonColor);
                    break;
            }
        }
    
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

void Board::Spawn(TileType tile, const Snake& snake){
    Random rng;
    int x,y;
    
    do{
    x = rng.GetInt(0, width-1);
    y = rng.GetInt(0, height-1);
    } while (GetType(x, y) != TileType::None || snake.CollideSnake({x,y}));
    
    pBoard[y*width + x] = tile;
}


Board::TileType Board::GetType(int x, int y) const{
    return pBoard[y*width + x];
}
Board::TileType Board::GetType(const iVec2& pos) const{
    return GetType(pos.x, pos.y);
}

void Board::DeleteTile(int x, int y){
    pBoard[y*width + x] = TileType::None;
}
void Board::DeleteTile(const iVec2& pos){
    DeleteTile(pos.x, pos.y);
}

void  Board::Restart(){
    for (int i = 0; i<width*height; ++i) {
        pBoard[i] = TileType::None;
    }
}






}
