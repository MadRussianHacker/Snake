/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "SDL.h"

#include "Player.hpp"
#include "Food.hpp"

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

    float deltaTime;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    int m_windowWidth, m_windowHeight;
    Player player;
    Food food;
};

#endif //SNAKE_GAME_HPP