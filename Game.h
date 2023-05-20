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

#define Max_inGame 4//Indice de texto en pantalla de juego

//clase principal de objeto juego
class Game {
public:
    Game();//constructor
    virtual ~Game();//destructor
    void initWindow();//inicializador de ventana
    void run();//funcion para correr juego
    void update();//funcion de actualizacion de juego
    void render();//funcion de rendering de juego
    void updateInput();//actualización de inputs en juego
    void updatePollEvents();//actualización de pollings de la aplicación
    //funciones de renderización
    void renderMap();
    void renderText();
    void renderFantasmas();
    //actualización de parámetros de juego
    void updateText();
    void updateMap();
    void updatePoints();
    void updatePowerUps();
    void updateLevel();
    void updateFantasmas();
    void updatePlayerPos();

private:
    sf::RenderWindow* window;//ventana de juego
    //funciones de inicialización de variables
    void initPlayer();
    void initFantasmas();
    void initMap();
    void initText();
    void initPowerUpList();
    void initPOINTS();
    //funciones de generación de objetos
    void spawnPowerUp();
    void respawnPlayer();
    //funcion de seguimiento de camino
    void moveToPowerup(Fantasma* fantasma);
    //parámetros de texto en pantalla

    sf::Text text[Max_inGame];
    sf::Font minecraftFont;
    //objeto jugador principal
    Player * player;
    //contadores de datos de juego
    int liveCounter;
    int pointCounter;
    int levelCounter;
    //tamaño de mapa
    int TILE_SIZE;
    //constantes de arreglo del tablero
    static const int ROWS = 10;
    static const int COLS = 10;
    //matriz de tiles
    sf::RectangleShape TILE_MAP[ROWS][COLS];
    //Listas enlazadas de elementos en el mapa
    PointLinkedList* POINTS;
    PowerUpLinkedList* POWERUPS;
    //Método A estrella
    std::vector<sf::Vector2f> Astar(sf::Vector2f start,sf::Vector2f finish);
    //Método de Backtracking
    std::vector<sf::Vector2f> Backtracking(sf::Vector2f start,sf::Vector2f finish);
    //Función auxiliar que retorna distancia manhattan
    int manhattanDist(sf::Vector2f currentPosition,sf::Vector2f finish);
    //vector de posición de jugador
    sf::Vector2f playerPos;
    //función auxiliar para búsqueda de camino
    std::vector<int> getIndex(sf::Vector2f pos);
    //vector de fantasmas
    std::vector<Fantasma*> fantasmas;
    //condicional de fin de juego
    bool gameOver;
    //struct de Nodo para A estrella
    struct Node {
        std::vector<int> tilePosition;
        int G;//costo de movimiento
        int H;//dist manhattan
        int F; // Puntaje Total de celda
        Node* parent; // parent node in the path
    };
    //Struct de nodo para algoritmo de backtracking
    struct NodeBacktrack {
        std::vector<int> tilePosition;

        NodeBacktrack* parent; // parent node in the path
    };

    //condicional de powerup en mapa
    bool spawnedPowerUp;
    bool pathMade;

};


#endif //PROYECTO2DATOSII_GAME_H
