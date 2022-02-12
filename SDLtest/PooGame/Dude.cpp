#include "Dude.hpp"
namespace PooGame{
Dude::Dude(){Restart();}

void Dude::Restart(){pos = {390.0,290.0};}

void Dude::Draw(Graphics& gfx) const{
    gfx.PutPixel( 7 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 8 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 9 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 10 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,0 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,1 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,1 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,2 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,2 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,3 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,3 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,3 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,4 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,4 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,4 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 13 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,5 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,5 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,6 + pos.y,255,255,255 );
    gfx.PutPixel( 4 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,6 + pos.y,255,255,255 );
    gfx.PutPixel( 12 + pos.x,6 + pos.y,255,255,255 );
    gfx.PutPixel( 13 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,6 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,6 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 3 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 4 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 12 + pos.x,7 + pos.y,255,255,255 );
    gfx.PutPixel( 13 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,7 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,7 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 3 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 4 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 5 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 12 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 13 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 14 + pos.x,8 + pos.y,255,255,255 );
    gfx.PutPixel( 15 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,8 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,8 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 13 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,9 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,9 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,10 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 14 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,10 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,10 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,11 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 7 + pos.x,11 + pos.y,20,14,18 );
    gfx.PutPixel( 8 + pos.x,11 + pos.y,18,11,14 );
    gfx.PutPixel( 9 + pos.x,11 + pos.y,18,12,14 );
    gfx.PutPixel( 10 + pos.x,11 + pos.y,18,12,14 );
    gfx.PutPixel( 11 + pos.x,11 + pos.y,21,13,16 );
    gfx.PutPixel( 12 + pos.x,11 + pos.y,24,11,15 );
    gfx.PutPixel( 13 + pos.x,11 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 15 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,11 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,11 + pos.y,0,0,0 );
    gfx.PutPixel( 0 + pos.x,12 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 2 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 6 + pos.x,12 + pos.y,23,9,23 );
    gfx.PutPixel( 7 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 9 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 10 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 11 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 12 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 13 + pos.x,12 + pos.y,135,26,68 );
    gfx.PutPixel( 14 + pos.x,12 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 16 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,12 + pos.y,254,221,88 );
    gfx.PutPixel( 19 + pos.x,12 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 5 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 9 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 10 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 11 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 12 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 13 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 14 + pos.x,13 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,13 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,13 + pos.y,0,0,0 );
    gfx.PutPixel( 1 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 3 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 6 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 9 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 10 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 11 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 12 + pos.x,14 + pos.y,251,192,224 );
    gfx.PutPixel( 13 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 14 + pos.x,14 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,14 + pos.y,254,221,88 );
    gfx.PutPixel( 18 + pos.x,14 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,15 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 6 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 9 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 10 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 11 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 12 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 13 + pos.x,15 + pos.y,251,192,224 );
    gfx.PutPixel( 14 + pos.x,15 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,15 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,15 + pos.y,0,0,0 );
    gfx.PutPixel( 2 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,16 + pos.y,254,221,88 );
    gfx.PutPixel( 4 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 6 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 7 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 8 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 9 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 10 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 11 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 12 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 13 + pos.x,16 + pos.y,251,192,224 );
    gfx.PutPixel( 14 + pos.x,16 + pos.y,135,26,68 );
    gfx.PutPixel( 15 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,16 + pos.y,254,221,88 );
    gfx.PutPixel( 17 + pos.x,16 + pos.y,0,0,0 );
    gfx.PutPixel( 3 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 4 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 8 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 9 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 10 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 13 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 15 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 16 + pos.x,17 + pos.y,0,0,0 );
    gfx.PutPixel( 5 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 6 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 8 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 9 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 10 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 11 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 12 + pos.x,18 + pos.y,254,221,88 );
    gfx.PutPixel( 13 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 14 + pos.x,18 + pos.y,0,0,0 );
    gfx.PutPixel( 7 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 8 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 9 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 10 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 11 + pos.x,19 + pos.y,0,0,0 );
    gfx.PutPixel( 12 + pos.x,19 + pos.y,0,0,0 );
    
}

void Dude::Update(const MainWindow& wnd, double dt){
    dVec2 posChange;
    if(wnd.mouse.LeftIsPressed()){
        posChange = wnd.mouse.GetPos() - (pos + dVec2(SIZE/2, SIZE/2));
        if (posChange.GetLengthSq() <=3)
            posChange = {0,0};
    }else{
        if (wnd.kbd.IsPressed('w'))
            posChange += {0,-1};
        if (wnd.kbd.IsPressed('s'))
            posChange += {0,1};
        if (wnd.kbd.IsPressed('a'))
            posChange += {-1,0};
        if (wnd.kbd.IsPressed('d'))
            posChange += {1,0};
    }
    
    posChange.Normalize();
    posChange *= speed*dt;
    pos += posChange;
    
    while(CheckWindowCollisionAndFit(wnd));
}

Rect Dude::GetRect() const {return Rect(pos,SIZE,SIZE);}

bool Dude::CheckWindowCollisionAndFit(const MainWindow &wnd){
    Rect rect(pos,SIZE,SIZE);
    Rect::Collision collision = rect.IsCollideWindow(wnd);
    
    if(collision == Rect::Collision::None)
        return false;
    
    if (collision == Rect::Collision::Left) {
        pos.x = 0.0;
    }
    
    if (collision == Rect::Collision::Top) {
        pos.y = 0.0;
    }
    
    if (collision == Rect::Collision::Right) {
        pos.x = wnd.GetWidth() - SIZE;
    }
        
    if (collision == Rect::Collision::Bottom) {
        pos.y = wnd.GetHeight() - SIZE;
    }
    return true;
}






}


