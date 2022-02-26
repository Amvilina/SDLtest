#include "MineSweeper.hpp"
#include "SpriteCodex.hpp"
MineSweeper::MineSweeper():
small{iVec2(87, 250), 100, 100},
medium{{88*2 + 100, 225}, 150, 150},
big{{88*3 + 150 + 100, 200}, 200, 200}
{}

void MineSweeper::UpdateModel(){
    
    if(isMainMenu){
        if (small.IsCollideMouse(wnd) && wnd.kbd.IsReleased(' ')) {
            isMainMenu = false;
            field.Reset(gfx.GetRect().GetCenter(),5 , 10, 4);
        }
        if (medium.IsCollideMouse(wnd) && wnd.kbd.IsReleased(' ')) {
            isMainMenu = false;
            field.Reset(gfx.GetRect().GetCenter(),20 , 20, 8);
        }
        if (big.IsCollideMouse(wnd) && wnd.kbd.IsReleased(' ')) {
            isMainMenu = false;
            field.Reset(gfx.GetRect().GetCenter(),80 , 40, 16);
        }
    }else if (field.GetState() == MineField::State::Playing)
    {
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
    }else{
        if(wnd.kbd.IsReleased(' '))
            isMainMenu = true;
    }
}

void MineSweeper::ComposeFrame(){
    if(isMainMenu){
        gfx.DrawRect(small, color);
        gfx.DrawRect(medium, color);
        gfx.DrawRect(big, color);
    }else{
    field.Draw(gfx);
    if(field.GetState() == MineField::State::Win)
        SpriteCodex::DrawWin(gfx.GetRect().GetCenter(), gfx);
    }
}
