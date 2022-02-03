#pragma once
#include "Game.hpp"

class PooGame : public Game {
public:
    PooGame();
private:
    
    void UpdateModel() override;
    void ComposeFrame() override;
    
    class Poo{
    public:
        Poo();
        void Draw(Graphics& gfx) const;
        void Update(const MainWindow& wnd);
        
        Vec2 pos;
        Vec2 speed;
        static constexpr int SIZE = 40;
        bool isEaten;
    };
    
    
    class Dude{
    public:
        Dude(double x, double y);
        void Draw(Graphics& gfx) const;
        void Update(const MainWindow& wnd);
        void TryToEatPoo(Poo& poo);
        
        Vec2 pos;
        static constexpr int SIZE = 20;
    };
    
    
    
    Dude dude;
    static const int NUMBER_OF_POOS = 10;
    Poo poos[10];

    bool isStart;
};
