/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/
#include "Error.hpp"
#include "Game.hpp"

Game::Game(int windowWidth, int windowHeight){
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
}

Game::~Game(){
    cleanup();
}

int Game::run(){
    if(initialize() != 0)
        return 1;
    while(running)
    {
        handleEvents();
        update();
        render();
    }
    return 0;
}

void Game::cleanup(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT)
            running = false;
    }
}

void Game::update(){
}

void Game::render() const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

int Game::initialize(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        logError("Can't initialize SDL" + std::string(SDL_GetError()));
        return 1;
    }

    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED,
             SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN);
    if(window == nullptr){
        logError("Can't create window: " + std::string(SDL_GetError()));
        SDL_Quit();
        return 1;
    }
    renderer = SDL_CreateRenderer(window, -1, 
               SDL_RENDERER_ACCELERATED | 
               SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr){
        logError("Can't create renderer: "+ std::string(SDL_GetError()));
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    running = true;
    return 0;
}