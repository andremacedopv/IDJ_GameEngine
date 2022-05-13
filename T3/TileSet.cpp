#include "./include/TileSet.h"
#include <math.h>

TileSet::TileSet(int tileW, int tileH, std::string file) {
    auto go = new GameObject();
    const char * ch = file.c_str();
    tileSet = new Sprite(*go, ch);

    tileWidth = tileW;
    tileHeight = tileH;

    rows = round(tileSet->GetWidth() / tileW);
    columns = round(tileSet->GetHeight() / tileH);
}

void TileSet::RenderTile(unsigned index, float x, float y) {
    if (index > 0 && (int)index < (rows * columns)-1) {
        int row = round(index / columns);   
        int column = round(index % columns);

        tileSet->SetClip(column * tileWidth, row * tileHeight, tileWidth, tileHeight);
        tileSet->Render(x, y);
    }
}
    
int TileSet::GetTileWidth() {
    return tileWidth;
}

int TileSet::GetTileHeight() {
    return tileHeight;
}