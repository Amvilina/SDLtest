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
    Character(const std::string& path, const Vec2& pos, int width, int height, double speed, int animationCount, Color chromo);
public:
    void Draw(Graphics& gfx) const;
    void Update(double dt);
    void SetDir(const Vec2& dir);
    
    void ActivateEffect(double duration, const Color& color);
    
    void SetGhostMode(double ratio);
    void CancelGhostMode();
private:
    Surface surface;
    
    Vec2 pos;
    int width;
    int height;
    
    Vec2 direction = {0 , 1};
    double speed;
    
    std::vector<Animation> animations;
    Action curAnimation = Action::StandingBottom;
    static constexpr double speedAnimationRatio = 0.001;
    
    Color effectColor;
    bool isEffectActive = false;
    double effectDuration;
    
    bool isGhost = false;
    double ghostRatio;
};


