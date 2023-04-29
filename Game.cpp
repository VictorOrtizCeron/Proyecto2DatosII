//
// Created by vortizc on 4/28/23.
//

#include "Game.h"

void Game::initWindow(){

    this-> window = new sf::RenderWindow(sf::VideoMode(800, 800), "Ventana de Juego");
    this-> window ->setFramerateLimit(60);
    this-> window ->setVerticalSyncEnabled(false);
}

void Game::initPlayer() {
    this->player= new Player();
}
Game::Game(){
    this->initWindow();
    this->initPlayer();
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

        std::cout<<"w is pressed"<<std::endl;
    }
}
void Game::update(){

    this->updatePollEvents();
    this->updateInput();
}

void Game::render(){
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