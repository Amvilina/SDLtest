#pragma once
#include "Surface.hpp"
#include "Graphics.hpp"

class Font {
public:
    Font(const std::string& path, Color chroma);
    void DrawText(const std::string& text,const iVec2& pos, const Color& textColor, Graphics& gfx) const;
private:
    Rect MapChar(char c) const;
private:
    Surface surface;
    
    int glyphWidth;
    int glyphHeight;
    
    static constexpr int nColumns = 32;
    static constexpr int nRows = 3;
    
    Color chroma;
    
    static constexpr char firstChar = ' ';
    static constexpr char lastChar = '~';
};
