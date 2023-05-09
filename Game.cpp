//
// Created by vortizc on 4/28/23.
//

#include "Game.h"

void Game::initWindow() {

    this->window = new sf::RenderWindow(sf::VideoMode(600, 700), "Ventana de Juego");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initText() {

    if (!this->minecraftFont.loadFromFile("/home/vortizc/Downloads/Minecraft.ttf")) {
        std::cout << "fallo la carga de font" << std::endl;
    }

    this->text[0].setFont(this->minecraftFont);
    this->text[0].setString("Lives:");
    this->text[0].setCharacterSize(20);
    this->text[0].setFillColor(sf::Color::White);
    this->text[0].setPosition(40, 630);

    this->text[1].setFont(this->minecraftFont);
    this->text[1].setString("Points:");
    this->text[1].setCharacterSize(20);
    this->text[1].setFillColor(sf::Color::White);
    this->text[1].setPosition(190, 630);

    this->text[2].setFont(this->minecraftFont);
    this->text[2].setString("Level: ");
    this->text[2].setCharacterSize(20);
    this->text[2].setFillColor(sf::Color::White);
    this->text[2].setPosition(340, 630);


}

void Game::initMap() {

    this->POINTS = new PointLinkedList();
    this->TILE_SIZE = 60;
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


    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (tileMap[y][x] == 1) {
                this->TILE_MAP[y][x].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                this->TILE_MAP[y][x].setFillColor(sf::Color::Transparent);
                this->TILE_MAP[y][x].setOutlineThickness(-2);
                this->TILE_MAP[y][x].setOutlineColor(sf::Color::Blue);

            } else {
                this->TILE_MAP[y][x].setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                this->TILE_MAP[y][x].setFillColor(sf::Color::Black);

                Point *newPoint = new Point();
                newPoint->setPosition(x * TILE_SIZE + 25, y * TILE_SIZE + 25);

                POINTS->addFirst(newPoint);

            }
            this->TILE_MAP[y][x].setPosition(x * TILE_SIZE, y * TILE_SIZE);

        }
    }

}

void Game::renderMap() {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            this->window->draw(this->TILE_MAP[y][x]);
        }
    }
}

void Game::updateMap() {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Color color = this->TILE_MAP[y][x].getFillColor();
            sf::FloatRect bounds = this->TILE_MAP[y][x].getGlobalBounds();

            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->isMovingUp &&
                    color == sf::Color::Transparent
                    ) {


                this->collisionTop = true;
                this->isMovingUp = false;


            }
            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->isMovingDown &&
                    color == sf::Color::Transparent
                    ) {


                this->collisionBot = true;
                this->isMovingDown = false;

            }
            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->isMovingLeft &&
                    color == sf::Color::Transparent
                    ) {


                this->collisionLeft = true;
                this->isMovingLeft = false;

            }
            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->isMovingRight &&
                    color == sf::Color::Transparent
                    ) {


                this->collisionRight = true;
                this->isMovingRight = false;

            }
        }
    }
}

void Game::updatePoints() {

    PointNode *current = this->POINTS->head;

    while (current != nullptr) {


        if (current->point->getBounds().intersects(this->player->getBounds())) {
            Point *pointPTR = POINTS->removePoint(current->point);
            pointCounter += 10;
            delete pointPTR;

        }
        current = current->nextPoint;
    }

}

void Game::initPlayer() {
    this->player = new Player();
}

void Game::initPowerUpList() {
    this->POWERUPS = new PowerUpLinkedList();
}

Game::Game() {
    this->initWindow();

    this->initPlayer();
    this->initMap();
    this->initPowerUpList();
    this->initText();
    levelCounter = 1;
    pointCounter = 0;
    liveCounter = 3;
    isMovingUp = false;
    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;
    collisionTop = false;
    collisionRight = false;
    collisionBot = false;
    collisionLeft = false;
    spawnedPowerUp = false;
}

Game::~Game() {
    delete this->window;

}

void Game::updatePollEvents() {
    sf::Event evento;
    while (this->window->pollEvent(evento)) {
        if (evento.Event::type == sf::Event::Closed)
            this->window->close();
        if (evento.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::updateInput() {

    this->canMoveLeft = true;
    this->canMoveRight = true;
    this->canMoveUp = true;
    this->canMoveDown = true;

    if (this->player->getBounds().left < 5 || collisionLeft) {
        canMoveLeft = false;
    }
    if (this->player->getBounds().left + 65 > 600 || collisionRight) {
        canMoveRight = false;
    }
    if (this->player->getBounds().top < 5 || collisionTop) {
        canMoveUp = false;
    }
    if (this->player->getBounds().top + 65 > 600 || collisionBot) {
        canMoveDown = false;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canMoveUp) {

        this->isMovingUp = true;
        this->isMovingDown = false;
        this->canMoveDown = true;
        this->canMoveLeft = false;
        this->canMoveRight = false;
        collisionBot = false;
        this->player->move(0, -2.f);

    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canMoveDown) {
        this->isMovingDown = true;
        this->isMovingUp = false;
        this->canMoveUp = true;
        this->canMoveLeft = false;
        this->canMoveRight = false;
        collisionTop = false;
        this->player->move(0, 2.f);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canMoveLeft) {
        this->isMovingLeft = true;
        this->isMovingRight = false;
        this->canMoveRight = true;

        collisionRight = false;

        this->player->move(-2.f, 0);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMoveRight) {
        this->isMovingRight = true;
        this->isMovingLeft = false;
        this->canMoveLeft = true;
        collisionLeft = false;
        this->player->move(2.f, 0);

    }


}

void Game::spawnPowerUp() {

    int x = rand() % 10;
    int y = rand() % 10;

    if (TILE_MAP[y][x].getFillColor() == sf::Color::Black) {
        //std::cout << "spawn PowerUp baby " << x << "," << y << std::endl;
        PowerUp *newPowerUp = new PowerUp();
        newPowerUp->setPosition(this->TILE_SIZE * x+20, this->TILE_SIZE * y+20);
        POWERUPS->addFirst(newPowerUp);

    }
    else{
        spawnPowerUp();
    }

}

void Game::updatePowerUps() {
    //std::cout<<POWERUPS->size<<std::endl;
    if (pointCounter % 200 == 0 && !spawnedPowerUp) {

        this->spawnPowerUp();
        spawnedPowerUp = true;

    }
    if (pointCounter % 200 != 0 && spawnedPowerUp) {
        spawnedPowerUp = false;
    }

}

void Game::updateText() {

    this->text[0].setString("Lives: " + std::to_string(liveCounter));
    this->text[1].setString("Points: " + std::to_string(pointCounter));
    this->text[2].setString("Level: " + std::to_string(levelCounter));

}


void Game::renderText() {

    for (int i = 0; i < 4; i++) {
        this->window->draw(text[i]);
    }

}


void Game::update() {

    this->updatePollEvents();
    this->updateInput();
    //this->player->update();
    this->updateMap();
    this->updatePoints();
    this->updateText();
    this->updatePowerUps();

}

void Game::render() {

    this->window->clear();
    this->renderText();
    this->renderMap();
    this->player->render(*this->window);
    this->POINTS->renderPointList(*this->window);
    this->POWERUPS->renderPowerUpList(*this->window);
    this->window->display();

}

void Game::run() {

    while (this->window->isOpen()) {
        this->update();
        this->render();

    }

}

