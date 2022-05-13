#include "./include/TileMap.h"
#include <iostream>
#include <fstream>
#include <regex>

// Função seguinte pega de https://pt.stackoverflow.com/questions/448483/implementa%C3%A7%C3%A3o-do-split-em-c
std::vector<std::string> split(const std::string& text, char sep)
{
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;

    while ((end = text.find(sep, start)) != std::string::npos)
    {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(text.substr(start));
    return tokens;
}

TileMap::TileMap(GameObject & associated, std::string file, TileSet * ts) : Component(associated) {
    Load(file);
    tileSet = ts;
}

void TileMap::Load(std::string file) {
    std::ifstream f (file);
    if(!f.is_open()){
        std::cout << "Erro ao abrir arquivo de map" << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(f, line);
    std::vector<std::string> dimensions = split(line, ',');
    mapWidth = std::stoi(dimensions[0]);
    mapHeight = std::stoi(dimensions[1]);
    mapDepth = std::stoi(dimensions[2]);

    while(!f.eof()) {
        std::getline(f, line);
        if(!line.empty()) {
            std::vector<std::string> values = split(line, ',');
            for(const auto &v: values) {
                if(!v.empty()) {
                    std::regex reg("^[0-9]{1,10}$");
                    if(std::regex_match(v, reg)){
                        tileMatrix.push_back(std::stoi(v));
                    }
                }
            }
        }
    }

    f.close();
}

void TileMap::SetTileSet(TileSet * ts) {
    tileSet = ts;
}

int & TileMap::At(int x, int y, int z){
    unsigned index = x + (y * mapWidth) + (z * mapWidth * mapHeight);
    return tileMatrix[index];
}

void TileMap::Render() {
    for (int i = 0; i < mapDepth; i++) {
        RenderLayer(i, 0, 0);
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY = 0) {
    int n = 0;
    for(int i = 0; i < mapWidth; i++) {
        for(int j = 0; j < mapHeight; j++) {
            int index = (layer * mapHeight * mapWidth) + n;
            int x = i * tileSet->GetTileWidth();
            int y = j * tileSet->GetTileHeight();
            tileSet->RenderTile(tileMatrix[index], x, y);
        }
    }
}

int TileMap::GetWidth() {
    return mapWidth;
}

int TileMap::GetHeight() {
    return mapHeight;
}

int TileMap::GetDepth() {
    return mapDepth;
}

void TileMap::Update(float dt) {

}

bool TileMap::Is(std::string type) {
    return type == "TileMap";
}