#include "./include/Resources.h"
#include "./include/Game.h"
#include <iostream>

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture * Resources::GetImage(std::string file) {
    auto search = imageTable.find(file);
    if(search == imageTable.end()) {
        const char * ch = file.c_str();
        SDL_Texture * texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), ch);
        if (texture == nullptr) {
            std::cout << "Error loading texture" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(1);
        } else {
            imageTable[file] = texture;
            return texture;
        }
    } else {
       return search->second; 
    }
}

void Resources::ClearImages() {
    for (auto i: imageTable) {
        SDL_DestroyTexture(i.second);
    }
    imageTable.clear();
}

Mix_Music * Resources::GetMusic(std::string file) {
    auto search = musicTable.find(file);
    if(search == musicTable.end()) {
        const char * ch = file.c_str();
        Mix_Music * music = Mix_LoadMUS(ch);
        if (music == nullptr) {
            std::cout << "Error loading music" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(1);
        } else {
            musicTable[file] = music;
            return music;
        }
    } else {
       return search->second; 
    }
}

void Resources::ClearMusics() {
    for (auto i: musicTable) {
        Mix_FreeMusic(i.second);
    }
    musicTable.clear();
}

Mix_Chunk * Resources::GetSound(std::string file) {
    auto search = soundTable.find(file);
    if(search == soundTable.end()) {
        const char * ch = file.c_str();
        Mix_Chunk * sound = Mix_LoadWAV(ch);
        if (sound == nullptr) {
            std::cout << "Error loading sound" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            exit(1);
        } else {
            soundTable[file] = sound;
            return sound;
        }
    } else {
       return search->second; 
    }
}

void Resources::ClearSounds() {
    for (auto i: soundTable) {
        Mix_FreeChunk(i.second);
    }
    soundTable.clear();
}