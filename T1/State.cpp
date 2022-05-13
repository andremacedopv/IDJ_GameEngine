#include "./include/State.h"
#include "./include/Game.h"
#include <iostream>

State::State() {
    quitRequested = false;
    auto bg = new Sprite();
}

void State::LoadAssets() {
    bg.Open("img/ocean.jpg");
    music.Open("audio/stageState.ogg");
    music.Play(-1);
}

void State::Update(float dt) {
    if(SDL_QuitRequested() == SDL_TRUE) {
        quitRequested = true;
    }
}

void State::Render() {
    bg.Render(0, 0);
}

bool State::QuitRequested() {
    return quitRequested;
}
