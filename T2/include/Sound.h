#ifndef SOUND_H_
#define SOUND_H_

#include "SDL_include.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <string>
#include "Component.h"

class Sound : public Component{
private:
    Mix_Chunk * chunk;
    int channel;

public:
    Sound(GameObject & associated);
    Sound(GameObject & associated, std::string file);
    ~Sound();

    void Play(int times);
    void Stop();
    void Open(std::string file);
    bool IsOpen();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
};

#endif