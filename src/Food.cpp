/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#include <cstdlib>
#include <ctime>
#include "Food.hpp"

Food::Food(){
    std::srand(std::time(nullptr));
    rect.w = 10;
    rect.h = 10;
    (*this).setRandomPosition();
}

void Food::setRandomPosition(){
    rect.x = ((std::rand()%50)+1)*10;
    rect.y = ((std::rand()%50)+1)*10;
}

glm::vec2 Food::getPosition() const {
    return glm::vec2(static_cast<float>(rect.x),
                     static_cast<float>(rect.y));
}

void Food::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}