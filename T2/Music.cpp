#include "./include/Music.h"
#include <iostream>

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) {
    music = nullptr;
    Open(file);
}

void Music::Play(int times = -1) {
    if(music != nullptr) {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop = 1500) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file) {
    if (music != nullptr) {
        Mix_FreeMusic(music);
        music = nullptr;
    }

    const char * ch = file.c_str();
    music = Mix_LoadMUS(ch);
    if (music == nullptr) {
        std::cout << "Error on Music Load" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }
}

bool Music::IsOpen() {
    return (music != nullptr);
}

Music::~Music() {
    Mix_FreeMusic(music);
}