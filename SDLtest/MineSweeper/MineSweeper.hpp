#pragma once
#include "Game.hpp"
#include "MineField.hpp"

class MineSweeper : public Game{
public:
    MineSweeper();
private:
    void UpdateModel() override;
    void ComposeFrame() override;
    
    MineField field;
    bool mousePressed = false;
};
