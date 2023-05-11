//
// Created by vortizc on 4/28/23.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Fantasma.h"
#include "Point.h"
#include "PointNode.h"
#include "PointLinkedList.h"
#include "PowerUp.h"
#include "PowerUpNode.h"
#include "PowerUpLinkedList.h"
#include  <random>
#ifndef PROYECTO2DATOSII_GAME_H
#define PROYECTO2DATOSII_GAME_H

#define Max_inGame 4
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
    void renderText();
    void updateText();
    void updateMap();
    void updatePoints();
    void updatePowerUps();
    void updateFantasma();
    void updatePlayerPos();

private:
    sf::RenderWindow* window;
    void initPlayer();
    void initFantasma();
    void initMap();
    void initText();
    void initPowerUpList();
    void initPOINTS();
    void spawnPowerUp();
    void respawnPlayer();
    PowerUp*powerUp;
    sf::Text text[Max_inGame];
    sf::Font minecraftFont;
    Player * player;
    Fantasma * protoFantasma;
    int liveCounter;
    int pointCounter;
    int levelCounter;
    int TILE_SIZE;
    static const int ROWS = 10;
    static const int COLS = 10;
    static const int points = 100;
    sf::RectangleShape TILE_MAP[ROWS][COLS];
    PointLinkedList* POINTS;
    PowerUpLinkedList* POWERUPS;

    sf::Vector2f playerPos;

    bool spawnedPowerUp;


};


#endif //PROYECTO2DATOSII_GAME_H
