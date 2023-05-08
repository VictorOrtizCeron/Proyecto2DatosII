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
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


    };
    const int TILE_SIZE = 60;
    //sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (tileMap[y][x] == 1) {
                this->TILE_MAP[y][x].setSize(sf::Vector2f(TILE_SIZE,TILE_SIZE));
                this->TILE_MAP[y][x].setFillColor(sf::Color::Blue);
            } else {
                this->TILE_MAP[y][x].setSize(sf::Vector2f(TILE_SIZE,TILE_SIZE));
                this->TILE_MAP[y][x].setFillColor(sf::Color::Black);
            }
            this->TILE_MAP[y][x].setPosition(x * TILE_SIZE, y * TILE_SIZE);
            this->window->draw(this->TILE_MAP[y][x]);
        }
    }

}
void Game::renderMap(){

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            this->window->draw(this->TILE_MAP[y][x]);
        }
    }
}
void Game:: updateMap(){

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Color color = this->TILE_MAP[y][x].getFillColor();
            sf::FloatRect bounds = this->TILE_MAP[y][x].getGlobalBounds();

            if(
                    this->player->getBounds().intersects(bounds)&&
                    this->isMovingUp&&
                    color == sf::Color::Blue
                    ){

               //wTILE_MAP[y][x].setFillColor(sf::Color::Red);

                this-> collisionTop = true;
                this->isMovingUp = false;

            }
            if(
                    this->player->getBounds().intersects(bounds)&&
                    this->isMovingDown&&
                    color == sf::Color::Blue
                    ){


                this-> collisionBot = true;
                this->isMovingDown = false;
            }
            if(
                    this->player->getBounds().intersects(bounds)&&
                    this->isMovingLeft&&
                    color == sf::Color::Blue
                    ){


                this-> collisionLeft= true;
                this->isMovingLeft = false;
            }
            if(
                    this->player->getBounds().intersects(bounds)&&
                    this->isMovingRight&&
                    color == sf::Color::Blue
                    ){


                this-> collisionRight = true;
                this->isMovingRight = false;
            }

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
    isMovingUp = false ;
    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    canMoveUp =true ;
    canMoveDown = true ;
    canMoveLeft = true ;
    canMoveRight =true ;
    collisionTop = false;
}
Game::~Game(){
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

     this->canMoveLeft = true;
     this->canMoveRight = true;
     this->canMoveUp = true;
     this->canMoveDown = true;
     if(this->player->getBounds().left<0) {
         canMoveLeft = false;
     }
     if(this->player->getBounds().left+50>600) {
         canMoveRight = false;
     }
     if(this->player->getBounds().top<0) {
         canMoveUp = false;
     }
     if(this->player->getBounds().top+50>600) {
         canMoveDown = false;
     }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canMoveUp && !collisionTop) {
                    //bools de deteccion de colisiones
                    this->isMovingUp = true;
                    this->isMovingDown = false;
                    this->canMoveDown = true;

                    this->canMoveLeft = false;
                    this->canMoveRight = false;


                    collisionBot = false;
                    this->player->move(0, -2.f);

                }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canMoveDown && !collisionBot) {
                    this->isMovingDown = true;
                    this->isMovingUp = false;


                    this->canMoveLeft = false;
                    this->canMoveRight = false;


                    collisionTop = false;

                    this->player->move(0, 2.f);

                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canMoveLeft && !collisionLeft) {
                    this->isMovingLeft = true;
                    this->isMovingRight = false;
                    this->canMoveRight = true;


                    collisionRight = false;


                    this->player->move(-2.f, 0);

                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMoveRight && !collisionRight) {
                    this->isMovingRight = true;
                    this->isMovingLeft = false;

                    collisionLeft = false;


                    this->player->move(2.f, 0);

                }





}
void Game::update(){

    this->updatePollEvents();
    this->updateInput();
    //this->player->update();
    this->updateMap();

}

void Game::render(){
    this->window->clear();
    this->renderMap();
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