#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "./include/Game.h"
#include "./include/Resources.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game* Game::instance{nullptr};

Game::Game(const char * title, int width, int height) {
    if(instance != nullptr) {
        std::cout << "Game alredy exists!" << std::endl;
        exit(1);
    }

    instance = this;

    srand(time(NULL));

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MP3);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024); 
    Mix_AllocateChannels(32);  

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0); 
    if (window == nullptr) {
        std::cout << "Error on window creation" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "Error on renderer creation" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }    

    state = new State();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();

    SDL_Quit();
}

Game & Game::GetInstance() {
    if(instance != nullptr) {
        return *instance;
    }

    instance = new Game("André Macedo - 170005950", 1024, 600);
    return *instance;
}

State & Game::GetState() {
    return *state;
}

SDL_Renderer * Game::GetRenderer() {
    return renderer;
}

void Game::Run() {
    state->LoadAssets();

    while(state->QuitRequested() == false) {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}