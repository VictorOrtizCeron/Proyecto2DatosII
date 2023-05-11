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


void Game::initPlayer() {
    this->player = new Player();
    this->playerPos = player->getPos();
}

void Game::initFantasma() {
    this->protoFantasma = new Fantasma(3);
    protoFantasma->circulo.setPosition(60 * 8, 60 * 8);
}

void Game::initPowerUpList() {
    this->POWERUPS = new PowerUpLinkedList();
}

Game::Game() {
    this->initWindow();

    this->initPlayer();
    this->initFantasma();
    this->initMap();
    this->initPowerUpList();
    this->initText();
    levelCounter = 1;
    pointCounter = 0;
    liveCounter = 3;
    this->spawnedPowerUp = false;
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

    this->player->canMoveLeft = true;
    this->player->canMoveRight = true;
    this->player->canMoveUp = true;
    this->player->canMoveDown = true;

    if (this->player->getBounds().left < 5 || player->collisionLeft) {
        player->canMoveLeft = false;
    }
    if (this->player->getBounds().left + 65 > 600 || player->collisionRight) {
        player->canMoveRight = false;
    }
    if (this->player->getBounds().top < 5 || player->collisionTop) {
        player->canMoveUp = false;
    }
    if (this->player->getBounds().top + 65 > 600 || player->collisionBot) {
        player->canMoveDown = false;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player->canMoveUp) {

        this->player->isMovingUp = true;
        this->player->isMovingDown = false;
        this->player->canMoveDown = true;
        this->player->canMoveLeft = false;
        this->player->canMoveRight = false;
        player->collisionBot = false;
        this->player->move(0, -2.f);

    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player->canMoveDown) {
        this->player->isMovingDown = true;
        this->player->isMovingUp = false;
        this->player->canMoveUp = true;
        this->player->canMoveLeft = false;
        this->player->canMoveRight = false;
        this->player->collisionTop = false;
        this->player->move(0, 2.f);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->canMoveLeft) {
        this->player->isMovingLeft = true;
        this->player->isMovingRight = false;
        this->player->canMoveRight = true;

        player->collisionRight = false;

        this->player->move(-2.f, 0);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->canMoveRight) {
        this->player->isMovingRight = true;
        this->player->isMovingLeft = false;
        this->player->canMoveLeft = true;
        this->player->collisionLeft = false;
        this->player->move(2.f, 0);

    }


}

void Game::spawnPowerUp() {

    int x = rand() % 10;
    int y = rand() % 10;

    if (TILE_MAP[y][x].getFillColor() == sf::Color::Black) {
        //std::cout << "spawn PowerUp baby " << x << "," << y << std::endl;
        PowerUp *newPowerUp = new PowerUp();
        newPowerUp->setPosition(this->TILE_SIZE * x + 20, this->TILE_SIZE * y + 20);
        POWERUPS->addFirst(newPowerUp);

    } else {
        spawnPowerUp();
    }

}

void Game::updatePowerUps() {

    if (pointCounter % 200 == 0 && !spawnedPowerUp) {

        this->spawnPowerUp();
        spawnedPowerUp = true;

    }
    if (pointCounter % 200 != 0 && spawnedPowerUp) {
        spawnedPowerUp = false;
    }

    PowerUpNode *current = this->POWERUPS->head;

    while (current != nullptr) {
        if (current->powerUp->getBounds().intersects(this->player->getBounds())) {
            PowerUp *powerUpPTR = POWERUPS->removePowerUp(current->powerUp);
            delete powerUpPTR;
        }
        current = current->nextPowerUp;
    }

}

void Game::updateMap() {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Color color = this->TILE_MAP[y][x].getFillColor();
            sf::FloatRect bounds = this->TILE_MAP[y][x].getGlobalBounds();
            bounds.width = 65.f;
            bounds.height = 65.f;

            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->player->isMovingUp &&
                    color == sf::Color::Transparent
                    ) {


                this->player->collisionTop = true;
                this->player->isMovingUp = false;


            }
            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->player->isMovingDown &&
                    color == sf::Color::Transparent
                    ) {


                this->player->collisionBot = true;
                this->player->isMovingDown = false;

            }
            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->player->isMovingLeft &&
                    color == sf::Color::Transparent
                    ) {


                this->player->collisionLeft = true;
                this->player->isMovingLeft = false;

            }
            if (
                    this->player->getBounds().intersects(bounds) &&
                    this->player->isMovingRight &&
                    color == sf::Color::Transparent

                    ) {


                this->player->collisionRight = true;
                this->player->isMovingRight = false;

            }
            if(protoFantasma->getBounds().intersects(bounds) &&
                color == sf::Color::Transparent&&
                this->protoFantasma->isMovingUp){
                protoFantasma->canMoveUp = false;
                protoFantasma->canMoveDown = true;

                std::cout<<"colisiona"<<std::endl;
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


void Game::updatePlayerPos() {
    this->playerPos = player->getPos();
}

void Game::updateFantasma() {




    if (protoFantasma->getPos().x > playerPos.x  && protoFantasma->canMoveLeft) {
        protoFantasma->move(-1.f, 0.f);

    } else if (protoFantasma->getPos().x < playerPos.x && protoFantasma->canMoveRight) {
        protoFantasma->move(1.f, 0.f);


    } else if (protoFantasma->getPos().y > playerPos.y && protoFantasma->canMoveUp) {
        this->protoFantasma->isMovingUp = true;
        this->player->isMovingDown = false;
        this->player->isMovingRight = false;
        this -> player->isMovingLeft = false;
        protoFantasma->move(0, -1.f);

    } else if (protoFantasma->getPos().y < playerPos.y && protoFantasma->canMoveDown) {
        protoFantasma->move(0, 1.f);
    } else if (protoFantasma->getPos().x == playerPos.x) {
        if (protoFantasma->getPos().y == playerPos.y) {
            protoFantasma->move(0, 0);
        }


    }


}

void Game::update() {

    this->updatePollEvents();
    this->updateInput();
    this->updatePlayerPos();
    this->updateFantasma();
    this->updateMap();
    this->updatePoints();
    this->updateText();
    this->updatePowerUps();

}

void Game::render() {

    this->window->clear();
    this->renderMap();
    this->renderText();

    this->POINTS->renderPointList(*this->window);
    this->POWERUPS->renderPowerUpList(*this->window);

    this->player->render(*this->window);

    this->protoFantasma->render(*this->window);

    this->window->display();

}

void Game::run() {

    while (this->window->isOpen()) {
        this->update();
        this->render();

    }

}

