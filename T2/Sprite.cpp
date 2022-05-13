#include "./include/Sprite.h"
#include "./include/Game.h"
#include <iostream>

Sprite::Sprite(GameObject & associated) : Component(associated) {
    texture = nullptr;
}

Sprite::Sprite(GameObject & associated, const char * file) :  Component(associated) {
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

    associated.box.w = width;
    associated.box.h = height;
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

void Sprite::Render() {
    Render((int)associated.box.x, (int)associated.box.y);
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

void Sprite::Update(float dt) {

}

bool Sprite::Is(std::string type) {
    return type == "Sprite";
}