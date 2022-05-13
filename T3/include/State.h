#ifndef STATE_H_
#define STATE_H_

#include "SDL_include.h"
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Music.h"
#include <memory>
#include "GameObject.h"

class State {
private:
    Music music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

public:
    State();
    ~State();

    void Input();
    void AddObject(int mouseX, int mouseY);
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};

#endif