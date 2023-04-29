//
// Created by vortizc on 4/28/23.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef PROYECTO2DATOSII_GAME_H
#define PROYECTO2DATOSII_GAME_H


class Game {
public:
    Game();
    virtual ~Game();
    void initWindow();
    void run();
    void update();
    void render();
    void updateInput();
    void updatePollEvents();



private:
    sf::RenderWindow* window;


};


#endif //PROYECTO2DATOSII_GAME_H
