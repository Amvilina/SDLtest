#pragma once
#include "Graphics.hpp"
#include "Vec2_.hpp"

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
        
        void Draw(const Vei2& screenPos, MineField::State gameState, Graphics& gfx) const;
        
        bool HasNoNeighbourMines() const;
        void SetNeighbourMinesCount(int n);
        
    private:
        State state = State::Hidden;
        bool hasBomb = false;
        int nNeighbourBombs = -1;
    };
public:
    ~MineField();
    
    void Reset(const Vei2& center, int nBombs, int width, int height);
    void Draw(Graphics& gfx) const;
    RectI GetRect() const;
    void OnRevealClick(const Vei2& screenPos);
    void OnFlagClick(const Vei2& screenPos);
    State GetState() const;
private:
    void RevealTile( const Vei2& gridPos );
    Tile& TileAt( const Vei2& gridPos );
    const Tile& TileAt( const Vei2& gridPos ) const;
    Vei2 ScreenToGrid( const Vei2& screenPos );
    int CountNeighborMemes( const Vei2& gridPos );
    bool GameIsWon() const;
private:
    int width;
    int height;
    static constexpr int borderThickness = 10;
    static constexpr Color borderColor = Colors::Blue;
    Vei2 topLeft;
    State state = State::Playing;
    Tile *field = nullptr;
};
