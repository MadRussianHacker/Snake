/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/
#include "Player.hpp"

Player::Player()
:m_speed(0.1f),
m_direction(RIGHT){
    tail = {
        Segment(glm::vec2(300.0f, 300.0f)),
        Segment(glm::vec2(300.0f-Segment::SIZE*1, 300.0f)),
        Segment(glm::vec2(300.0f-Segment::SIZE*2, 300.0f))
    };
}

const glm::vec2 Player::directionVector[] = {
        {0.0f, -Segment::SIZE}, //UP
        {0.0f, Segment::SIZE},  //DOWN
        {-Segment::SIZE, 0.0f}, //LEFT
        {Segment::SIZE, 0.0f} //RIGHT
    };

void Player::setSpeed(float speed){
    m_speed = speed;
}

void Player::grow(){
    tail.push_back(Segment(glm::vec2(-12.0f, -12.0f)));
}

void Player::setDirection(Direction direction){
    if((int)m_direction+(int)direction==5) return;
    if((int)m_direction+(int)direction==1) return;
    m_direction = direction;
}

void Player::draw(SDL_Renderer* renderer) const {
    for(auto x : tail)
        x.draw(renderer);
}

void Player::update(float deltaTime){
    static float counter = 0;
    counter += deltaTime;
    if(counter >= m_speed){
        updateTail(tail.begin());
        counter = 0;
    }
}

void Player::updateTail(std::list<Segment>::iterator it, glm::vec2 pos){
    if(it == tail.begin()){
        pos = (*it).getPosition();
        (*it).move(directionVector[m_direction]);
        updateTail(++it, pos);
        return;
    }
    glm::vec2 tmp = (*it).getPosition();
    (*it).setPosition(pos);
    if(it == tail.end()) return;
    updateTail(++it, tmp);
}