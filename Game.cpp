//
// Created by vortizc on 4/28/23.
//

#include "Game.h"

void Game::initWindow(){

    this-> window = new sf::RenderWindow(sf::VideoMode(600, 600), "Ventana de Juego");
    this-> window ->setFramerateLimit(60);
    this-> window ->setVerticalSyncEnabled(false);
}
void Game::initMap(){

    int tileMap[10][10] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}


    };
    const int TILE_SIZE = 60;
    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (tileMap[x][y] == 1) {
                tile.setFillColor(sf::Color::Blue);
            } else {
                tile.setFillColor(sf::Color::Black);
            }
            tile.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            this->window->draw(tile);
        }
    }

}
void Game::initPlayer() {
    this->player= new Player();
}
Game::Game(){
    this->initWindow();
    this->initPlayer();
    this->initMap();
}
Game::~Game()
{
    delete this->window;

}
void Game::updatePollEvents() {
    sf::Event evento;
    while(this->window->pollEvent(evento))
    {
        if(evento.Event::type==sf::Event::Closed)
            this->window->close();
        if(evento.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}
 void Game::updateInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

        this->player->move(0, -2.f);

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

         this->player->move(0, 2.f);

     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

         this->player->move(-2.f, 0);

     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

         this->player->move(2.f,0);

     }
}
void Game::update(){

    this->updatePollEvents();
    this->updateInput();
    //this->player->update();

}

void Game::render(){
    this->window->clear();
    this->initMap();
    this->player->render(*this->window);

    this->window->display();
}
void Game::run()
{

    while(this->window->isOpen())
    {
        this->update();
        this->render();

    }

}