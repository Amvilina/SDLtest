#pragma once
#include "Game.hpp"

class MineSweeper : public Game{
public:
    class Tile{
    public:
        enum class State{
            Hidden,
            Revealed,
            Flaged
        };
        bool hasBomb;
    };
    
};
