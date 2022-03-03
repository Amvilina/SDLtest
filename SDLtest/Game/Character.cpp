#include "Character.hpp"

Character::Character(const std::string& path, const dVec2& pos, int width, int height, double speed, int animationCount, Color chromo)
:
surface(path),
pos(pos),
width(width),
height(height),
speed(speed)
{
    for (int i = 0; i<int(Action::StandingLeft); ++i) {
        animations.emplace_back(Animation(surface, width, height*i, width, height, animationCount, speedAnimationRatio * speed, chromo));
    }
    
    for (int i = int(Action::StandingLeft); i<int(Action::Count); ++i) {
        animations.emplace_back(Animation(surface, 0, height*(i-int(Action::StandingLeft)), width, height, 1,speedAnimationRatio * speed, chromo));
    }
}

void Character::Draw(Graphics& gfx) const{
    if(isEffectActive)
        animations[int(curAnimation)].DrawSubstitute(pos, gfx, Colors::Red);
    else
        animations[int(curAnimation)].Draw(pos, gfx, gfx.GetRect());
}

void Character::Update(double dt){
    
    if(isEffectActive){
        effectDuration -= dt;
        if(effectDuration <= 0.0)
            isEffectActive = false;
    }
    
    pos += direction * speed * dt;
    animations[int(curAnimation)].Update(dt);
}

void Character::SetDir(const dVec2& dir){
    if (dir.x > 0.0) {
        curAnimation = Action::WalkingRight;
    }else if (dir.x < 0.0){
        curAnimation = Action::WalkingLeft;
    }else if (dir.y > 0.0){
        curAnimation = Action::WalkingBottom;
    }else if (dir.y < 0.0){
        curAnimation = Action::WalkingTop;
    }
    else if (direction.x > 0.0){
        curAnimation = Action::StandingRight;
    }else if (direction.x < 0.0){
        curAnimation = Action::StandingLeft;
    }else if (direction.y > 0.0){
        curAnimation = Action::StandingBottom;
    }else if (direction.y < 0.0){
        curAnimation = Action::StandingTop;
    }
    
    direction = dir.GetNormalized();

}

void Character::ActivateEffect(double duration, const Color& color){
    effectDuration = duration;
    effectColor = color;
    isEffectActive = true;
}
