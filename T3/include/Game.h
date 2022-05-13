#ifndef GAME_H_
#define GAME_H_

#include "SDL_include.h"
#include <SDL2/SDL.h>
#include "State.h"

class Game {
private:
    static Game * instance;
    SDL_Window * window;
    SDL_Renderer * renderer;
    State* state;

public:
    Game(const char * title, int width, int height);
    ~Game();

    void Run();
    SDL_Renderer * GetRenderer();
    State & GetState();
    static Game & GetInstance();
};

#endif