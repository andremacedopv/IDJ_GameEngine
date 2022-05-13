#include "./include/Sprite.h"
#include "./include/Game.h"
#include <iostream>

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(const char * file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void Sprite::Open(const char * file) {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file);
    if (texture == nullptr) {
        std::cout << "Texture null" << std::endl; 
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)) {
        std::cout << "Error on query texture" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    SDL_Rect dstRect = clipRect;
    dstRect.x = x;
    dstRect.y = y;
    if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect)) {
        std::cout << "Error on Render Copy" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

bool Sprite::IsOpen() {
    return (texture != nullptr);
}