#include "Font.hpp"

Font::Font(const std::string& path, Color chroma)
:
surface (path),
glyphWidth (surface.GetWidth() / nColumns),
glyphHeight (surface.GetHeight() / nRows),
chroma (chroma)
{
    assert(glyphWidth * nColumns == surface.GetWidth());
    assert(glyphHeight * nRows == surface.GetHeight());
}

void Font::DrawText(const std::string& text,const iVec2& pos, const Color& textColor, Graphics& gfx) const{
    int x = pos.x;
    int y = pos.y;
    
    for(auto c : text){
        
        if (c == '\n') {
            x = pos.x;
            y += glyphHeight;
            continue;
        }
        
        if(c == ' '){
            x += glyphWidth;
            continue;
        }
        
        if (c > firstChar && c <= lastChar) {
            gfx.DrawSurfaceSubstitute(x, y, surface, MapChar(c), chroma, textColor);
            x += glyphWidth;
        }
        
    }
}

Rect Font::MapChar(char c) const{
    assert(c >= firstChar && c <= lastChar);
    int nGlyph = c - firstChar;
    
    int x = nGlyph % nColumns;
    int y = nGlyph / nColumns;
    
    return Rect( x * glyphWidth , y * glyphHeight , glyphWidth, glyphHeight);
}
