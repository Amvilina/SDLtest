#pragma once
#include <SDL.h>
#include <iostream>

class Keyboard{
public:

    bool IsPressed(const SDL_Event& event, int scanCode);
    bool IsReleased(const SDL_Event& event, int scanCode);
    
private:
};



//class Keyboard {
//public:
//
//    Keyboard(){
//        for (int i = 0; i<5; ++i) {
//            keys[i].key = Key::Keys(i);
//        }
//    }
//
//    bool isPressedUP(){return keys[int(Key::Keys::UP)].isPressed;}
//    bool isPressedDOWN(){return keys[int(Key::Keys::DOWN)].isPressed;}
//    bool isPressedLEFT(){return keys[int(Key::Keys::LEFT)].isPressed;}
//    bool isPressedRIGHT(){return keys[int(Key::Keys::RIGHT)].isPressed;}
//    bool isPressedSPACE(){return keys[int(Key::Keys::SPACE)].isPressed;}
//
//    bool isActiveUP(){return keys[int(Key::Keys::UP)].isActive;}
//    bool isActiveDOWN(){return keys[int(Key::Keys::DOWN)].isActive;}
//    bool isActiveLEFT(){return keys[int(Key::Keys::LEFT)].isActive;}
//    bool isActiveRIGHT(){return keys[int(Key::Keys::RIGHT)].isActive;}
//    bool isActiveSPACE(){return keys[int(Key::Keys::SPACE)].isActive;}
//
//    bool isReleasedUP(){return keys[int(Key::Keys::UP)].isReleased;}
//    bool isReleasedDOWN(){return keys[int(Key::Keys::DOWN)].isReleased;}
//    bool isReleasedLEFT(){return keys[int(Key::Keys::LEFT)].isReleased;}
//    bool isReleasedRIGHT(){return keys[int(Key::Keys::RIGHT)].isReleased;}
//    bool isReleasedSPACE(){return keys[int(Key::Keys::SPACE)].isReleased;}
//
//    void HadleEvent(const SDL_Event& event){
//        keys[int(Key::Keys::UP)].isPressed = false;
//        keys[int(Key::Keys::DOWN)].isPressed = false;
//        keys[int(Key::Keys::LEFT)].isPressed = false;
//        keys[int(Key::Keys::RIGHT)].isPressed = false;
//        keys[int(Key::Keys::SPACE)].isPressed = false;
//
//        keys[int(Key::Keys::UP)].isReleased = false;
//        keys[int(Key::Keys::DOWN)].isReleased = false;
//        keys[int(Key::Keys::LEFT)].isReleased = false;
//        keys[int(Key::Keys::RIGHT)].isReleased = false;
//        keys[int(Key::Keys::SPACE)].isReleased = false;
//
//        switch (event.type) {
//            case SDL_KEYDOWN:
//                if (event.key.keysym.sym == SDLK_UP) {
//                    if(keys[int(Key::Keys::UP)].isActive){
//                        keys[int(Key::Keys::UP)].isPressed = false;}
//                    else{
//                        keys[int(Key::Keys::UP)].isPressed = true;}
//                    keys[int(Key::Keys::UP)].isActive = true;
//
//                }
//                if (event.key.keysym.sym == SDLK_DOWN) {
//                    if(keys[int(Key::Keys::DOWN)].isActive){
//                        keys[int(Key::Keys::DOWN)].isPressed = false;}
//                    else{
//                        keys[int(Key::Keys::DOWN)].isPressed = true;}
//                    keys[int(Key::Keys::DOWN)].isActive = true;
//
//                }
//                if (event.key.keysym.sym == SDLK_LEFT) {
//                    if (keys[int(Key::Keys::LEFT)].isActive) {
//                        keys[int(Key::Keys::LEFT)].isPressed = false;
//                    }else{
//                    keys[int(Key::Keys::LEFT)].isPressed = true;
//                    }
//                    keys[int(Key::Keys::LEFT)].isActive = true;
//
//                }
//                if (event.key.keysym.sym == SDLK_RIGHT) {
//                    if (keys[int(Key::Keys::RIGHT)].isActive) {
//                        keys[int(Key::Keys::RIGHT)].isPressed = false;
//                    }else{
//                        keys[int(Key::Keys::RIGHT)].isPressed = true;}
//                    keys[int(Key::Keys::RIGHT)].isActive = true;
//
//                }
//
//                if (event.key.keysym.sym == SDLK_SPACE) {
//                    if(keys[int(Key::Keys::SPACE)].isActive){
//                        keys[int(Key::Keys::SPACE)].isPressed = false;}
//                    else{
//                        keys[int(Key::Keys::SPACE)].isPressed = true;}
//                    keys[int(Key::Keys::SPACE)].isActive = true;
//
//                }
//
//                break;
//
//            case SDL_KEYUP:
//                if (event.key.keysym.sym == SDLK_UP) {
//                    keys[int(Key::Keys::UP)].isActive = false;
//                    keys[int(Key::Keys::UP)].isReleased = true;
//                }
//                if (event.key.keysym.sym == SDLK_DOWN) {
//                    keys[int(Key::Keys::DOWN)].isActive = false;
//                    keys[int(Key::Keys::DOWN)].isReleased = true;
//                }
//                if (event.key.keysym.sym == SDLK_LEFT) {
//                    keys[int(Key::Keys::LEFT)].isActive = false;
//                    keys[int(Key::Keys::LEFT)].isReleased = true;
//                }
//                if (event.key.keysym.sym == SDLK_RIGHT) {
//                    keys[int(Key::Keys::RIGHT)].isActive = false;
//                    keys[int(Key::Keys::RIGHT)].isReleased = true;
//                }
//                if (event.key.keysym.sym == SDLK_SPACE) {
//                    keys[int(Key::Keys::SPACE)].isActive = false;
//                    keys[int(Key::Keys::SPACE)].isReleased = true;
//                }
//                break;
//        }
//    }
//
//private:
//    bool UP, DOWN, LEFT, RIGTH;
//    bool Q, W, E, R, T, Y, U, I, O, P;
//    bool A, S, D, F, G, H, J, K, L;
//    bool Z, X, C, V, B, N;
//
//
//    class Key{
//    public:
//
//        enum Keys{
//            UP,
//            DOWN,
//            LEFT,
//            RIGHT,
//            SPACE
//        };
//
//        Key() : isPressed(0), isActive(0), isReleased(0){}
//
//        Keys key;
//
//        bool isPressed;
//        bool isActive;
//        bool isReleased;
//
//
//    };
//
//    Key keys[5];
//
//
//};
