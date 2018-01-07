/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/
#include <chrono>
#include <thread>
#include <iostream>
#include "Error.hpp"
#include "Game.hpp"

Game::Game(int windowWidth, int windowHeight){
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    deltaTime = 0.0f;
}

Game::~Game(){
    cleanup();
}

int Game::run(){
    if(initialize() != 0)
        return 1;
    while(running)
    {
        auto start = std::chrono::high_resolution_clock::now();
        handleEvents();
        update();
        render();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end-start;
        deltaTime = duration.count();
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
        if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym)
            {
                case SDLK_UP:
                    player.setDirection(UP);
                break;
                case SDLK_DOWN:
                    player.setDirection(DOWN);
                break;
                case SDLK_LEFT:
                    player.setDirection(LEFT);
                break;
                case SDLK_RIGHT:
                    player.setDirection(RIGHT);
                break;    
            }
        }
    }
}

void Game::update(){
    player.update(deltaTime);
    if((player.getHeadPosition().x == food.getPosition().x)
     &&(player.getHeadPosition().y == food.getPosition().y)){
        food.setRandomPosition();
        player.grow();
    }
    if(player.isDead()){
        std::cout<< "GAME OVER! \n";
        std::cout<< "Your result: "<<player.getPoints()<<"\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        running = false;
    }
}

void Game::render() const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    food.draw(renderer);
    player.draw(renderer);
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