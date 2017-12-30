/*
    simple snake clone
    Copyright 2017 by Michał Gibas
*/

#include "Game.hpp"

int main(int argc, char* argv[]){
    Game* game = new Game(800, 600);
    int errcode = game->run();
    delete game;
    return errcode;
}