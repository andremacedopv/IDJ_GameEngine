#include "./include/Sound.h"
#include "./include/Resources.h"
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
    chunk = Resources::GetSound(file);
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