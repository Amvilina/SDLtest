#pragma once
#include "Graphics.hpp"
#include "Color.hpp"



namespace SnakeGame{

class Board{
public:
    enum class TileType{
        None,
        Apple,
        Obstacle,
        Poison
    };
public:
    Board(Graphics& gfx);
    ~Board();
    
    void DrawCell(int x, int y, const Color& color);
    void DrawCell(const iVec2& pos, const Color& color);
    void DrawCellCircle(int x, int y, const Color& color);
    void DrawCellCircle(const iVec2& pos, const Color& color);
    void DrawBoard();
    void DrawBorder();
    
    void Spawn(TileType tile, const class Snake& snake);
    
    TileType GetType(int x, int y) const;
    TileType GetType(const iVec2& pos) const;
    
    void DeleteTile(int x, int y);
    void DeleteTile(const iVec2& pos);
    
    void Restart(int dimension, int width, int height);
    
    int GetWidth() const{return width;}
    int GetHeight() const{return height;}
    
private:
    
    int dimension;
    static constexpr int padding = 1;
    int width;
    int height;
    static constexpr int borderWidth = 5;
    int marginX;
    int marginY;
    
    static constexpr Color borderColor = Color(0x1E7E9C);
    static constexpr Color boardColor = Color(0x474747);
    
    static constexpr Color appleColor = Color(0xFF0B00);
    static constexpr Color obstacleColor = Color(0xCCCCCC);
    static constexpr Color poisonColor = Color(0x530BFF);
    
    
    TileType* pBoard = nullptr;
    
    Graphics& gfx;
};


}
