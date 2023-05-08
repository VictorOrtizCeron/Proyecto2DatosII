//
// Created by vortizc on 4/28/23.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Point.h"
#include "PointNode.h"
#include "PointLinkedList.h"
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
    void updatePoints();


private:
    sf::RenderWindow* window;
    void initPlayer();
    void initMap();
    void initPOINTS();
    Player * player;
    static const int ROWS = 10;
    static const int COLS = 10;
    static const int points = 100;
    sf::RectangleShape TILE_MAP[ROWS][COLS];
    PointLinkedList* POINTS;
    int PointCount;

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
