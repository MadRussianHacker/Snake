/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#include "Segment.hpp"

Segment::Segment(glm::vec2 position){
    rect.w = static_cast<int>(SIZE);
    rect.h = static_cast<int>(SIZE);
    (*this).setPosition(position);
}

const float Segment::SIZE = 10.0f;

void Segment::draw(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Segment::setPosition(glm::vec2 position){
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
}

void Segment::move(glm::vec2 offset){
    (*this).setPosition((*this).getPosition()+offset);
}

glm::vec2 Segment::getPosition() const {
    return glm::vec2(static_cast<float>(rect.x),
                     static_cast<float>(rect.y));
}
