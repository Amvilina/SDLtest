#pragma once
#include "Game.hpp"

class PooGame : public Game {
public:
    PooGame();
private:
    
    void UpdateModel() override;
    void ComposeFrame() override;
    
    class Dude{
    public:
        Dude(double x, double y, double width, double height);
        void Draw(Graphics& gfx) const;
        void Move(const MainWindow& wnd);
        Rect rect;
    };
    
    class Poo{
    public:
        Poo();
        void Draw(Graphics& gfx) const;
        void Move(const MainWindow& wnd);
        Rect rect;
        Vec2 speed;
        bool isEaten;
    };
    
    Dude dude;
    //static const int NUMBER_OF_POOS = 10;
    //Poo poos[10];
    Poo poo1;
    Poo poo2;
    
    bool isStart;
};
