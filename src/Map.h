//
// Created by mike on 28.12.2018.
//

#ifndef GSDL_MAP_H
#define GSDL_MAP_H

#include "Game.h"

class Map {
public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture *dirt;
    SDL_Texture *space;
    SDL_Texture *debry;

    int map[20][25];
};


#endif //GSDL_MAP_H
