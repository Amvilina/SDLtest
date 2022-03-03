#pragma once
#include "Animation.hpp"

class Character{
private:
    enum class Action{
        WalkingLeft,
        WalkingRight,
        WalkingTop,
        WalkingBottom,
        StandingLeft,
        StandingRight,
        StandingTop,
        StandingBottom,
        Count
    };
public:
    Character(const std::string& path, const dVec2& pos, int width, int height, double speed, int animationCount, Color chromo);
public:
    void Draw(Graphics& gfx) const;
    void Update(double dt);
    void SetDir(const dVec2& dir);
    
    void ActivateEffect(double duration, const Color& color);
private:
    Surface surface;
    
    dVec2 pos;
    int width;
    int height;
    
    dVec2 direction = {0 , 1};
    double speed;
    
    std::vector<Animation> animations;
    Action curAnimation = Action::StandingBottom;
    static constexpr double speedAnimationRatio = 0.001;
    
    Color effectColor;
    bool isEffectActive = false;
    double effectDuration;
};


