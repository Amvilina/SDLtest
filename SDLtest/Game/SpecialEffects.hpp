#pragma once
#include "Graphics.hpp"

namespace SpecialEffects {
    
    class Copy{
    public:
        void operator()(Graphics& gfx, int x, int y, Color c) const
        {
            gfx.PutPixel(x, y, c);
        }
    };
    
    class Chroma{
    public:
        Chroma(Color chromaColor) : chromaColor( chromaColor ) {}
        void operator()(Graphics& gfx, int x, int y, Color c) const
        {
            if (c != chromaColor)
                gfx.PutPixel(x, y, c);
        }
    private:
        Color chromaColor;
    };

    class Substitution{
    public:
        Substitution(Color substitutionColor, Color chromaColor) : substitutionColor( substitutionColor ) , chromaColor(chromaColor) {}
        void operator()(Graphics& gfx, int x, int y, Color c) const
        {
            if (c != chromaColor)
                gfx.PutPixel(x, y, substitutionColor);
        }
    private:
        Color substitutionColor;
        Color chromaColor;
    };
    
    class Ghost{
    public:
        Ghost(double ratio, Color chromaColor) : ratio( ratio ) , chromaColor( chromaColor ) {}
        void operator()(Graphics& gfx, int x, int y, Color c) const
        {
            if (c == chromaColor)
                return;
            
            Color backC = gfx.GetPixel(x , y);
            
            Color newC = Color(
                                backC.GetR() * (1-ratio) + c.GetR() * ratio,
                                backC.GetG() * (1-ratio) + c.GetG() * ratio,
                                backC.GetB() * (1-ratio) + c.GetB() * ratio
                                );
            
            gfx.PutPixel(x, y, newC);
        }
    private:
        double ratio;
        Color chromaColor;
    };
    

};
