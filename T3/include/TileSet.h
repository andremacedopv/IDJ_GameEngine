#ifndef TILE_SET_H_
#define TILE_SET_H_

#include "SDL_include.h"
#include <string>
#include "Sprite.h"

class TileSet {
private:
    Sprite * tileSet;
    int rows, columns;
    int tileWidth, tileHeight;

public:
    TileSet(int tileW, int tileH, std::string file);

    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
};

#endif