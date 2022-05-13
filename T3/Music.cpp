#include "./include/Music.h"
#include "./include/Resources.h"
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
        music = nullptr;
    }

    music = Resources::GetMusic(file);
}

bool Music::IsOpen() {
    return (music != nullptr);
}

Music::~Music() {
    Mix_FreeMusic(music);
}