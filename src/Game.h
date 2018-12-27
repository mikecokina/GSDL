//
// Created by mike on 27.12.2018.
//

#ifndef GSDL_GAME_H
#define GSDL_GAME_H


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <iostream>

class Game {
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
    bool setIsRunning();
    bool setIsNotRunning();

private:
    bool isRunning = false;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};


#endif /* GSDL_GAME_H */
