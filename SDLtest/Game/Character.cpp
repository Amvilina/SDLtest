#include "Character.hpp"
#include "SpecialEffects.hpp"

Character::Character(const std::string& path, const Vec2& pos, int width, int height, double speed, int animationCount, Color chromo)
:
surface(path),
pos(pos),
width(width),
height(height),
speed(speed)
{
    for (int i = 0; i<int(Action::StandingLeft); ++i) {
        animations.emplace_back(Animation(surface, width, height*i, width, height, animationCount, speedAnimationRatio * speed));
    }
    
    for (int i = int(Action::StandingLeft); i<int(Action::Count); ++i) {
        animations.emplace_back(Animation(surface, 0, height*(i-int(Action::StandingLeft)), width, height, 1,speedAnimationRatio * speed));
    }
}

void Character::Draw(Graphics& gfx) const{
    

    if(isEffectActive)
    {
        animations[int(curAnimation)].Draw(Vei2(pos), gfx, SpecialEffects::Substitution(Colors::Red, Colors::Magenta));
    }
    else if(!isGhost)
    {
        animations[int(curAnimation)].Draw(Vei2(pos), gfx, SpecialEffects::Chroma(Colors::Magenta));
    }
    else
    {
        animations[int(curAnimation)].Draw(Vei2(pos), gfx, SpecialEffects::Ghost(ghostRatio, Colors::Magenta));
    }
    
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

void Character::SetDir(const Vec2& dir){
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

void Character::SetGhostMode(double ratio){
    assert(ratio >= 0.0 && ratio <= 1.0);
    isGhost = true;
    ghostRatio = ratio;
}

void Character::CancelGhostMode(){
    isGhost = false;
}
