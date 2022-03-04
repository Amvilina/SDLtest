#include "Font.hpp"
#include "SpecialEffects.hpp"

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

void Font::DrawText(const std::string& text,const Vei2& pos, const Color& textColor, Graphics& gfx) const{
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
            gfx.DrawSurface(x, y, surface, MapChar(c), SpecialEffects::Substitution(textColor, chroma));
            x += glyphWidth;
        }
        
    }
}

RectI Font::MapChar(char c) const{
    assert(c >= firstChar && c <= lastChar);
    int nGlyph = c - firstChar;
    
    int x = nGlyph % nColumns;
    int y = nGlyph / nColumns;
    
    return RectI( Vei2{ x * glyphWidth , y * glyphHeight } , glyphWidth, glyphHeight);
}
