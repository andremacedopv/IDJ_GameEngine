#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL_include.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Component.h"
#include <string>

class Sprite : public Component{
private:
    SDL_Texture * texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite(GameObject & associated);
    Sprite(GameObject & associated, const char * file);
    ~Sprite();

    void Open(const char * file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    void Render();
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float dt);
    bool Is(std::string type);
};

#endif