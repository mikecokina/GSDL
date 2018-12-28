//
// Created by mike on 28.12.2018.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren, int x, int y) {
    renderer = ren;
    objTexture = TextureManager::LoadTexture(textureSheet, ren);

    xpos = x;
    ypos = y;
}

GameObject::~GameObject() = default;


void GameObject::Update() {

    xpos += 2;
    ypos++;

    srcRect.h = 128;
    srcRect.w = 128;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;

    destRect.w = srcRect.w * 1;
    destRect.h = srcRect.h * 1;

}

void GameObject::Render() {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}