#ifndef MUSIC_H_
#define MUSIC_H_

#include "SDL_include.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <string>

class Music {
private:
    Mix_Music * music;

public:
    Music();
    Music(std::string file);
    ~Music();

    void Play(int times);
    void Stop(int msToStop);
    void Open(std::string file);
    bool IsOpen();
};

#endif