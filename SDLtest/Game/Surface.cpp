#include "Surface.hpp"
#include <cassert>

Surface::Surface(const std::string& fileName){
    std::ifstream file(fileName, std::ios::binary);
    assert(file);
    
    BMPFileHeader  bmpFileHeader;
    BMPInfoHeader  bmpInfoHeader;
//    BMPColorHeader bmpColorHeader;
    
    file.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));
    assert(bmpFileHeader.file_type == 0x4D42);
    
    file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));
    assert(bmpInfoHeader.bit_count == 24 || bmpInfoHeader.bit_count == 32);
    assert(bmpInfoHeader.compression == 0);
    
//    assert(bmpInfoHeader.size >= sizeof(bmpInfoHeader) + sizeof(bmpColorHeader));
    
//    file.read(reinterpret_cast<char*>(&bmpColorHeader), sizeof(bmpColorHeader));
//    BMPColorHeader trueColorHeader;
//    assert(trueColorHeader.alpha_mask == bmpColorHeader.alpha_mask);
//    assert(trueColorHeader.blue_mask == bmpColorHeader.blue_mask);
//    assert(trueColorHeader.green_mask == bmpColorHeader.green_mask);
//    assert(trueColorHeader.red_mask == bmpColorHeader.red_mask);
//    assert(trueColorHeader.color_space_type == bmpColorHeader.color_space_type);
    
    file.seekg(bmpFileHeader.offset_data);
    
    width = bmpInfoHeader.width;
    height = bmpInfoHeader.height;
    
    bool is32 = (bmpInfoHeader.bit_count == 32);
    const int padding = is32 ? 0 : (4 - (width * 3) % 4) % 4;
    
    int yStart = height - 1;
    int yEnd = -1;
    int dy = -1;
    
    if (height < 0) {
        height = -height;
        yStart = 0;
        yEnd = height;
        dy = 1;
    }
    
    pPixels = new Color[width * height];
    
    for (int y = yStart; y != yEnd; y += dy) {
        for (int x = 0; x < width; ++x) {
            const uint8_t b = file.get();
            const uint8_t g = file.get();
            const uint8_t r = file.get();
            if(is32){
                const uint8_t a = file.get();
                PutPixel(x, y, Color(r,g,b,a));
            }else{
                PutPixel(x, y, Color(r,g,b));
            }
        }
        file.seekg(padding, std::ios::cur);
    }
}
                                    

Surface::Surface(int width, int height)
    :
    width(width),
    height(height),
    pPixels(new Color[width*height])
{}

Surface::~Surface(){
    delete [] pPixels;
}

Surface::Surface(const Surface& other)
{
    *this = other;
}

Surface& Surface::operator=(const Surface& other){
    if (this == &other) {
        return *this;
    }
    
    delete [] pPixels;
    
    width = other.width;
    height = other.height;
    const int nPixels = width*height;
    pPixels = new Color[nPixels];
    for (int i = 0; i<nPixels; ++i) {
        pPixels[i] = other.pPixels[i];
    }
    
    return *this;
}

void Surface::PutPixel(int x, int y, Color c){
    assert(x >= 0);
    assert(x <= width-1);
    assert(y >= 0);
    assert(y <= height-1);
    pPixels[y*width + x] = c;
}

Color Surface::GetPixel(int x, int y) const{
    assert(x >= 0);
    assert(x <= width-1);
    assert(y >= 0);
    assert(y <= height-1);
    return pPixels[y*width + x];
}

int Surface::GetWidth() const{
    return width;
}

int Surface::GetHeight() const{
    return height;
}

Rect Surface::GetRect() const{
    return Rect{0.0, 0.0, double(width), double(height)};
}
