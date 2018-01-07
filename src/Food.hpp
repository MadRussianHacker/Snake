/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#ifndef SNAKE_FOOD_HPP
#define SNAKE_FOOD_HPP

#include "SDL.h"
#include <glm/vec2.hpp>

class Food
{
public:
    Food();
    void setRandomPosition();
    glm::vec2 getPosition() const;
    void draw(SDL_Renderer* renderer) const;
private:
    SDL_Rect rect;
};

#endif //SNAKE_FOOD_HPP