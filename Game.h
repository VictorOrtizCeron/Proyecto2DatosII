//
// Created by vortizc on 4/28/23.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

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
    void renderMap();
    void updateMap();


private:
    sf::RenderWindow* window;
    void initPlayer();
    void initMap();
    Player * player;
    static const int ROWS = 10;
    static const int COLS = 10;
    sf::RectangleShape TILE_MAP[ROWS][COLS];
    bool isMovingUp ;
    bool isMovingDown ;
    bool isMovingLeft ;
    bool isMovingRight ;
    bool canMoveUp ;
    bool canMoveDown ;
    bool canMoveLeft ;
    bool canMoveRight ;
    bool collisionTop;
    bool collisionBot;
    bool collisionLeft;
    bool collisionRight;


};


#endif //PROYECTO2DATOSII_GAME_H
