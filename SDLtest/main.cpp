#include "Game.hpp"
#include "Rect.hpp"

class g:public Game{
    
    void UpdateModel() override{
        if (wnd.kbd.IsPressed('w'))
            dude.pos.y--;
        if (wnd.kbd.IsPressed('s'))
            dude.pos.y++;
        if (wnd.kbd.IsPressed('a'))
            dude.pos.x--;
        if (wnd.kbd.IsPressed('d'))
            dude.pos.x++;
        
        if(dude.IsCollide(box)){
            color.SetR(0);
        }else{
            color.SetR(255);
        }
        
        if(dude.IsCollideMouse(wnd)){
            color.SetR(0);
        }else{
            color.SetR(255);
        }
    }
    
    void ComposeFrame() override{
        gfx.SetColor(color);
        for (int i = dude.pos.x; i<dude.pos.x+dude.size.x; ++i) {
            for (int j = dude.pos.y; j<dude.pos.y+dude.size.y; ++j) {
                gfx.PutPixel(i, j);
            }
        }
        
        gfx.SetColor(255,255,255);
        for (int i = box.pos.x; i<box.pos.x+box.size.x; ++i) {
            for (int j = box.pos.y; j<box.pos.y+box.size.y; ++j) {
                gfx.PutPixel(i, j);
            }
        }
        
    }
    Color color = {255,255,255};
    Rect dude = Rect({70,50}, {10,10});
    Rect box = Rect({100,100}, {10,10});
};

int main(int argc, const char * argv[]) {
    
   
    g g;
    while(g.Go());
    
    
    return 0;
}
