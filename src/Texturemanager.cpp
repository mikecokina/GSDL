//
// Created by mike on 28.12.2018.
//

#include "TextureManager.h"

// LoadTexture implementation
SDL_Texture *TextureManager::LoadTexture(const char *texture, SDL_Renderer *ren) {
    SDL_Surface *tempSurface = IMG_Load(texture);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}
