//
// Created by vortizc on 4/28/23.
//
#include <iostream>
#include <cstdlib>
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
    void renderFantasmas();
    void updateText();
    void updateMap();
    void updatePoints();
    void updatePowerUps();
    void updateLevel();
    void updateFantasmas();
    void updatePlayerPos();

private:
    sf::RenderWindow* window;
    void initPlayer();
    void initFantasmas();
    void initMap();
    void initText();
    void initPowerUpList();
    void initPOINTS();
    void spawnPowerUp();
    void respawnPlayer();
    void moveToPowerup(Fantasma* fantasma);
    PowerUp*powerUp;
    sf::Text text[Max_inGame];
    sf::Font minecraftFont;
    Player * player;
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
    std::vector<sf::Vector2f> Astar(sf::Vector2f start,sf::Vector2f finish);
    std::vector<sf::Vector2f> Backtracking(sf::Vector2f start,sf::Vector2f finish);
    int manhattanDist(sf::Vector2f currentPosition,sf::Vector2f finish);
    sf::Vector2f playerPos;
    std::vector<int> getIndex(sf::Vector2f pos);
    std::vector<Fantasma*> fantasmas;
    bool gameOver;
    struct Node {
        std::vector<int> tilePosition;
        int G;//costo de movimiento
        int H;//dist manhattan
        int F; // Puntaje Total de celda
        Node* parent; // parent node in the path
    };
    struct NodeBacktrack {
        std::vector<int> tilePosition;

        NodeBacktrack* parent; // parent node in the path
    };


    bool spawnedPowerUp;
    bool pathMade;

};


#endif //PROYECTO2DATOSII_GAME_H
