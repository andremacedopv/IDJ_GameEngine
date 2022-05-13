#include "./include/Sound.h"
#include <iostream>

Sound::Sound(GameObject & associated) : Component(associated) {
    chunk = nullptr;
}

Sound::Sound(GameObject & associated, std::string file) : Component(associated) {
    chunk = nullptr;
    Open(file);
}

Sound::~Sound(){
    if(chunk != nullptr) {
        Stop();
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times = 1) {
    channel = Mix_PlayChannel(-1, chunk, times);
}

void Sound::Stop() {
    if(chunk != nullptr) {
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(std::string file) {
    const char * ch = file.c_str();
    chunk = Mix_LoadWAV(ch);

    if(chunk == nullptr) {
        std::cout << "Error on Sound Open" << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }
}

bool Sound::IsOpen() {
    return (chunk != nullptr);
}

void Sound::Update(float dt) {

}
    
void Sound::Render() {

}

bool Sound::Is(std::string type) {
    return type == "Sound";
}