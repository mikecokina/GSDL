//
// Created by mike on 28.12.2018.
//

#ifndef GSDL_GAMEOBJECT_H
#define GSDL_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos, ypos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;

};

#endif //GSDL_GAMEOBJECT_H
