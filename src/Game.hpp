/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "SDL.h"


class Game
{
public:
    Game(int windowWidth, int windowHeight);
    virtual ~Game();
    int run();
private:
    int initialize();
    void handleEvents();
    void update();
    void render() const;
    void cleanup();
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    int windowWidth, windowHeight;
};

#endif //SNAKE_GAME_HPP