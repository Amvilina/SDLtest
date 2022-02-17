#include "MineField.hpp"
#include "SpriteCodex.hpp"
#include "Random.hpp"

void MineField::Tile::SpawnBomb(){
    hasBomb = true;
}
bool MineField::Tile::HasBomb() const{
    return hasBomb;
}
void MineField::Tile::Reveal(){
    state = State::Revealed;
}
bool MineField::Tile::IsRevealed() const{
    return state == State::Revealed;
}
void MineField::Tile::ToggleFlag(){
    if(state == State::Flaged)
        state = State::Hidden;
    if(state == State::Hidden)
        state = State::Flaged;
}
bool MineField::Tile::IsFlagged() const{
    return state == State::Flaged;
}

void MineField::Tile::Draw(const iVec2& screenPos, MineField::State gameState, Graphics& gfx) const{
    if (gameState != MineField::State::Lost) {
        switch (state) {
            case State::Hidden:
                SpriteCodex::DrawTileButton(screenPos, gfx);
                break;
            case State::Flaged:
                SpriteCodex::DrawTileButton(screenPos, gfx);
                SpriteCodex::DrawTileFlag(screenPos, gfx);
                break;
            case State::Revealed:
                if(hasBomb)
                    SpriteCodex::DrawTileBomb(screenPos, gfx);
                else
                    SpriteCodex::DrawTileNumber(screenPos, nNeighbourBombs, gfx);
                break;
        }
    }else{
        switch (state) {
            case State::Hidden:
                if( hasBomb )
                {
                    SpriteCodex::DrawTileBomb( screenPos,gfx );
                }
                else
                {
                    SpriteCodex::DrawTileButton( screenPos,gfx );
                }
                break;
            case State::Flaged:
                if( hasBomb )
                {
                    SpriteCodex::DrawTileBomb( screenPos,gfx );
                    SpriteCodex::DrawTileFlag( screenPos,gfx );
                }
                else
                {
                    SpriteCodex::DrawTileBomb( screenPos,gfx );
                    SpriteCodex::DrawTileCross( screenPos,gfx );
                }
                break;
            case State::Revealed:
                if( !hasBomb )
                {
                    SpriteCodex::DrawTileNumber( screenPos,nNeighbourBombs,gfx );
                }
                else
                {
                    SpriteCodex::DrawTileBombRed( screenPos,gfx );
                }
                break;
        }
    }
}

bool MineField::Tile::HasNoNeighbourMines() const{
    return nNeighbourBombs == 0;
}
void MineField::Tile::SetNeighbourMinesCount(int n){
    nNeighbourBombs = n;
}

//===============================================

MineField::MineField(const iVec2& center, int nBombs)
:
topLeft(center - iVec2(width * SpriteCodex::tileSize, height * SpriteCodex::tileSize)/2)
{
    Random rng;
    
    for(int i = 0; i < nBombs; ++i){
        iVec2 spawnPos;
        do {
            spawnPos = rng.GetIntVec2(0, width-1, 0, height-1);
        } while (TileAt(spawnPos).HasBomb());
        
        TileAt(spawnPos).SpawnBomb();
    }
    
    for( iVec2 gridPos = { 0,0 }; gridPos.y < height; gridPos.y++ )
        {
            for( gridPos.x = 0; gridPos.x < width; gridPos.x++ )
            {
                TileAt( gridPos ).SetNeighbourMinesCount( CountNeighborMemes( gridPos ) );
            }
        }
}


void MineField::Draw( Graphics& gfx ) const
{
    gfx.DrawRect( GetRect().GetExpanded( borderThickness ),borderColor );
    gfx.DrawRect( GetRect(),SpriteCodex::baseColor );
    for( iVec2 gridPos = { 0,0 }; gridPos.y < height; gridPos.y++ )
    {
        for( gridPos.x = 0; gridPos.x < width; gridPos.x++ )
        {
            TileAt( gridPos ).Draw( topLeft + gridPos * SpriteCodex::tileSize,state,gfx );
        }
    }
}

Rect MineField::GetRect() const
{
    return Rect( topLeft,width * SpriteCodex::tileSize,height * SpriteCodex::tileSize );
}

void MineField::OnRevealClick( const iVec2& screenPos )
{
    if( state == State::Playing )
    {
        const iVec2 gridPos = ScreenToGrid( screenPos );
        RevealTile( gridPos );
        if( GameIsWon() )
        {
            state = State::Win;
        }
    }
}

void MineField::OnFlagClick( const iVec2 & screenPos )
{
    if( state == State::Playing )
    {
        const iVec2 gridPos = ScreenToGrid( screenPos );
        Tile& tile = TileAt( gridPos );
        if( !tile.IsRevealed() )
        {
            tile.ToggleFlag();
        }
    }
}

MineField::State MineField::GetState() const{
    return state;
}

void MineField::RevealTile( const iVec2& gridPos )
{
    Tile& tile = TileAt( gridPos );
    if( !tile.IsRevealed() && !tile.IsFlagged() )
    {
        tile.Reveal();
        if( tile.HasBomb() )
        {
            state = State::Lost;
        }
        else if( tile.HasNoNeighbourMines() )
        {
            const int xStart = std::max( 0,gridPos.x - 1 );
            const int yStart = std::max( 0,gridPos.y - 1 );
            const int xEnd = std::min( width - 1,gridPos.x + 1 );
            const int yEnd = std::min( height - 1,gridPos.y + 1 );

            for( iVec2 gridPos = { xStart,yStart }; gridPos.y <= yEnd; gridPos.y++ )
            {
                for( gridPos.x = xStart; gridPos.x <= xEnd; gridPos.x++ )
                {
                    RevealTile( gridPos );
                }
            }
        }
    }
}

MineField::Tile& MineField::TileAt( const iVec2& gridPos ){
    return field[gridPos.y * width + gridPos.x];
}

const MineField::Tile& MineField::TileAt( const iVec2& gridPos ) const{
    return field[gridPos.y * width + gridPos.x];
}

iVec2 MineField::ScreenToGrid( const iVec2& screenPos ){
    return (screenPos-topLeft) / SpriteCodex::tileSize;
}

int MineField::CountNeighborMemes( const iVec2& gridPos ){
    int count = 0;
    const int xStart = std::max( 0,gridPos.x - 1 );
    const int yStart = std::max( 0,gridPos.y - 1 );
    const int xEnd = std::min( width - 1,gridPos.x + 1 );
    const int yEnd = std::min( height - 1,gridPos.y + 1 );

    for( iVec2 gridPos = { xStart,yStart }; gridPos.y <= yEnd; gridPos.y++ )
    {
        for( gridPos.x = xStart; gridPos.x <= xEnd; gridPos.x++ )
        {
            if(TileAt(gridPos).HasBomb())
                count++;
        }
    }
    return count;
}

bool MineField::GameIsWon() const
{
    for( const Tile& t : field )
    {
        if( (t.HasBomb() && !t.IsFlagged()) ||
            (!t.HasBomb() && !t.IsRevealed()) )
        {
            return false;
        }
    }
    return true;
}
