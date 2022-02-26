#pragma once
#include "Graphics.hpp"
#include "iVec2.hpp"

class MineField{
public:
    enum class State{
        Playing,
        Win,
        Lost
    };
private:
    class Tile{
    public:
        enum class State{
            Hidden,
            Revealed,
            Flaged
        };
        void SpawnBomb();
        bool HasBomb() const;
        void Reveal();
        bool IsRevealed() const;
        void ToggleFlag();
        bool IsFlagged() const;
        
        void Draw(const iVec2& screenPos, MineField::State gameState, Graphics& gfx) const;
        
        bool HasNoNeighbourMines() const;
        void SetNeighbourMinesCount(int n);
        
    private:
        State state = State::Hidden;
        bool hasBomb = false;
        int nNeighbourBombs = -1;
    };
public:
    ~MineField();
    
    void Reset(const iVec2& center, int nBombs, int width, int height);
    void Draw(Graphics& gfx) const;
    Rect GetRect() const;
    void OnRevealClick(const iVec2& screenPos);
    void OnFlagClick(const iVec2& screenPos);
    State GetState() const;
private:
    void RevealTile( const iVec2& gridPos );
    Tile& TileAt( const iVec2& gridPos );
    const Tile& TileAt( const iVec2& gridPos ) const;
    iVec2 ScreenToGrid( const iVec2& screenPos );
    int CountNeighborMemes( const iVec2& gridPos );
    bool GameIsWon() const;
private:
    int width;
    int height;
    static constexpr int borderThickness = 10;
    static constexpr Color borderColor = Colors::Blue;
    iVec2 topLeft;
    State state = State::Playing;
    Tile *field = nullptr;
};
