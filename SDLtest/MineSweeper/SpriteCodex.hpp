#pragma once

#include "Graphics.hpp"
#include "iVec2.hpp"

class SpriteCodex
{
public:
    // width and height of all tiles
    static constexpr int tileSize = 16;
    // base color for all tiles
    static constexpr Color baseColor = { 192,192,192 };
    // 16x16 tile sprites assume (192,192,192) background and top left origin
    static void DrawTile0( const iVec2& pos,Graphics& gfx );
    static void DrawTile1( const iVec2& pos,Graphics& gfx );
    static void DrawTile2( const iVec2& pos,Graphics& gfx );
    static void DrawTile3( const iVec2& pos,Graphics& gfx );
    static void DrawTile4( const iVec2& pos,Graphics& gfx );
    static void DrawTile5( const iVec2& pos,Graphics& gfx );
    static void DrawTile6( const iVec2& pos,Graphics& gfx );
    static void DrawTile7( const iVec2& pos,Graphics& gfx );
    static void DrawTile8( const iVec2& pos,Graphics& gfx );
    static void DrawTileButton( const iVec2& pos,Graphics& gfx );
    static void DrawTileCross( const iVec2& pos,Graphics& gfx );
    static void DrawTileFlag( const iVec2& pos,Graphics& gfx );
    static void DrawTileBomb( const iVec2& pos,Graphics& gfx );
    static void DrawTileBombRed( const iVec2& pos,Graphics& gfx );
    // Tile selector function valid input 0-8
    static void DrawTileNumber( const iVec2& pos,int n,Graphics& gfx );
    // Win Screen 254x192 center origin
    static void DrawWin( const iVec2& pos,Graphics& gfx );
};
