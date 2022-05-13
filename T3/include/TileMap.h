#ifndef TILE_MAP_H_
#define TILE_MAP_H_

#include "SDL_include.h"
#include <string>
#include <vector>
#include "GameObject.h"
#include "Component.h"
#include "TileSet.h"

class TileMap : public Component {
private:
    std::vector<int> tileMatrix;
    TileSet * tileSet;
    int mapWidth, mapHeight, mapDepth;

public:
    TileMap(GameObject & associated, std::string file, TileSet * ts);

    void Load(std::string file);
    void SetTileSet(TileSet * ts);
    int & At(int x, int y, int z);
    void Render();
    void RenderLayer(int layer, int cameraX, int cameraY);
    int GetWidth();
    int GetHeight();
    int GetDepth();
    void Update(float dt);
    bool Is(std::string type);
};

#endif