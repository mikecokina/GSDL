//
// Created by mike on 28.12.2018.
//

#ifndef GSDL_TEXTUREMANAGER_H
#define GSDL_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *fileName);
    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);

};



#endif //GSDL_TEXTUREMANAGER_H
