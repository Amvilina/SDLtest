#include "MineSweeper.hpp"
#include "SpriteCodex.hpp"
MineSweeper::MineSweeper()
:
field(gfx.GetRect().GetCenter(), 80)
{
}

void MineSweeper::UpdateModel(){
    if (field.GetState() == MineField::State::Playing) {
        if (wnd.kbd.IsReleased('f')) {
            const iVec2 pos = wnd.mouse.GetPos();
            if(field.GetRect().IsCollideMouse(wnd))
                field.OnFlagClick(pos);
        }
        if (wnd.mouse.LeftIsPressed() && !mousePressed) {
            mousePressed = true;
            const iVec2 pos = wnd.mouse.GetPos();
            if(field.GetRect().IsCollideMouse(wnd))
                field.OnRevealClick(pos);
        }
        
        if(!wnd.mouse.LeftIsPressed())
            mousePressed = false;
    }
}

void MineSweeper::ComposeFrame(){
    field.Draw(gfx);
    if(field.GetState() == MineField::State::Win)
        SpriteCodex::DrawWin(gfx.GetRect().GetCenter(), gfx);
}
