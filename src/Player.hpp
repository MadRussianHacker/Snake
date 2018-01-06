/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#ifndef SNAKE_PLAYER_HPP
#define SNAKE_PLAYER_HPP

#include <iterator>
#include <list>
#include "Segment.hpp"

enum Direction
{
    UP,   
    DOWN, 
    LEFT, 
    RIGHT 
};

class Player
{
public:
    Player();
    void update(float deltaTime);
    void setSpeed(float speed);
    void setDirection(Direction direction);
    void grow();
    void draw(SDL_Renderer* renderer) const;
private:
    void updateTail(std::list<Segment>::iterator it, glm::vec2 pos=glm::vec2(0.0f, 0.0f));
    float m_speed;
    Direction m_direction;
    std::list<Segment> tail;

    const static glm::vec2 directionVector[4];
};

#endif //SNAKE_PLAYER_HPP