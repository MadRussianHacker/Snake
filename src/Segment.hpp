/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#ifndef SNAKE_SEGMENT_HPP
#define SNAKE_SEGMENT_HPP

#include "SDL.h"
#include <glm/glm.hpp>

class Segment
{
public:
    Segment(glm::vec2 position);
    void setPosition(glm::vec2 position);
    void move(glm::vec2 offset);
    void draw(SDL_Renderer* renderer) const;
    glm::vec2 getPosition() const;

    static const float SIZE;
private:
    SDL_Rect rect;
};

#endif //SNAKE_SEGMENT_HPP