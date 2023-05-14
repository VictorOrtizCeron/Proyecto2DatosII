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
        this->pathMade = false;
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

    void Game::respawnPlayer() {
        int x = rand() % 10;
        int y = rand() % 10;
        if (TILE_MAP[y][x].getFillColor() == sf::Color::Black) {
            this->player->setPosition(x * TILE_SIZE, y * TILE_SIZE);

        } else {
            spawnPowerUp();
        }
    }

    void Game::spawnPowerUp() {

        int x = rand() % 10;
        int y = rand() % 10;

        if (TILE_MAP[y][x].getFillColor() == sf::Color::Black && !this->player->getBounds().intersects(TILE_MAP[y][x].getGlobalBounds()) ) {

            PowerUp *newPowerUp = new PowerUp();
            newPowerUp->setPosition(this->TILE_SIZE * x + 20, this->TILE_SIZE * y + 20);
            POWERUPS->addFirst(newPowerUp);
            this->protoFantasma->isSearching = true;
            this->protoFantasma->isChasing = false;
            this->protoFantasma->isScattering = false;


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
                this->protoFantasma->isSearching = false;
                this->protoFantasma->isChasing = true;
                this->protoFantasma->isScattering = false;
                pathMade = false;
                delete powerUpPTR;
            }if (current->powerUp->getBounds().intersects(this->protoFantasma->getBounds())) {
                PowerUp *powerUpPTR = POWERUPS->removePowerUp(current->powerUp);

                this->protoFantasma->isSearching = false;
                this->protoFantasma->isChasing = true;
                this->protoFantasma->isScattering = false;
                pathMade = false;

                delete powerUpPTR;


            }
            current = current->nextPowerUp;
        }

    }

    std::vector<sf::Vector2f> Game::Astar(sf::Vector2f start, sf::Vector2f finish) {

        //Se define vector de camino para retornar
        std::vector<sf::Vector2f> path;
        //Se definen las listas abierta y cerrada
        std::vector<Node *> openList;
        std::vector<Node *> closedList;

        Node *startNode = new Node{start, manhattanDist(start, finish), nullptr};
        Node *endNode = new Node{finish, 0, nullptr};

        //Se agrega nodo inicial a openList

        openList.push_back(startNode);
        //std::cout << openList[0]->h << std::endl;
        while (!openList.empty()) {
            //se busca el indice del nodo con menor distancia manhattan
            int lowestIndex = 0;

            for (int i = 0; i < openList.size(); i++) {
                if (openList[i]->h < openList[lowestIndex]->h) {
                    lowestIndex = i;
                }
            }

            //se establece el nodo en el cual se realizaran las comparaciones (los pasos de las flechitas)
            Node *currentNode = openList[lowestIndex];

            //se evalúa si el nodo esta a la par del nodo de destino
            if (currentNode->h == endNode->h) {
                Node *node = currentNode;
                while (node != nullptr) {


                    //se inserta en la lista de camino
                    path.push_back(sf::Vector2f(node->tilePosition));
                    node = node->parent;
                }
                //se da vuelta a lista de camino para que vaya desde inicio a fin
                std::reverse(path.begin(), path.end());
                //se termina el bucle

                break;
            }
            // Si no se cumple la condición, se saca de la openList y se mete a la closedList.
            openList.erase(openList.begin() + lowestIndex);
            closedList.push_back(currentNode);

            //se genera un vector de Nodos que serán los hijos de nodo actual (los que tendran flechita)
            std::vector<Node *> successors;
            for (int y = -1; y <= 1; y++) {
                for (int x = -1; x <= 1; x++) {
                    //Condición para saltarse los casos diagonales
                    if (x != 0 && y != 0) {
                        continue;
                    }
                    int xPos = currentNode->tilePosition.x + x* 60;
                    int yPos = currentNode->tilePosition.y + y * 60;

                    // Ignore positions outside the map
                    if (xPos < 0 || xPos > 600 || yPos < 0 || yPos > 600) {
                        continue;
                    }
                    //ignora celdas fuera del mapa
                    if (this->TILE_MAP[yPos / 60][xPos / 60].getFillColor() == sf::Color::Transparent) {
                        continue;
                    }
                    // Create the successor node
                    sf::Vector2f newNodePos;
                    newNodePos.x = xPos;
                    newNodePos.y = yPos;
                    Node *successor = new Node{newNodePos, manhattanDist(newNodePos, finish), currentNode};

                    //SIGUE CHECKEAR SI YA EL NODO ESTA EN las listas
                    bool inClosedList = false;
                    for (Node *closedNode: closedList) {
                        if (closedNode->tilePosition.x == successor->tilePosition.x &&
                            closedNode->tilePosition.y == successor->tilePosition.y) {
                            inClosedList = true;

                            break;
                        }
                    }
                    if (inClosedList) {
                        continue;
                    }

                    bool inOpenList = false;
                    for (Node *openNode: openList) {
                        if (openNode->tilePosition.x == successor->tilePosition.x &&
                            openNode->tilePosition.y == successor->tilePosition.y) {
                            inOpenList = true;
                            break;
                        }
                    }
                    if (!inOpenList) {
                        // Add the successor to the open list
                        openList.push_back(successor);
                    } else {
                        // If the successor is already in the open list, check if the new path to it is better
                        for (Node *openNode: openList) {
                            if (openNode->tilePosition.x == successor->tilePosition.x &&
                                openNode->tilePosition.y == successor->tilePosition.y) {
                                if (successor->h < openNode->h) {
                                    openNode->h = successor->h;
                                    openNode->parent = currentNode;
                                }
                                else{delete successor;}
                                break;
                            }
                        }

                    }
                }

            }
        }

//        openList.~vector();
//        closedList.~vector();
//        delete(startNode);
//        delete(endNode);

        return path;
    }

    int Game::manhattanDist(sf::Vector2f currentPosition, sf::Vector2f finish) {
        int currentX = currentPosition.x / 60;
        int currentY = currentPosition.y / 60;
        int FinishX = finish.x / 60;
        int FinishY = finish.y / 60;
        int h = abs(currentX - FinishX) + abs(currentY - FinishY);
        return h;

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
                if (protoFantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    this->protoFantasma->isMovingUp) {
                    protoFantasma->canMoveUp = false;
                    protoFantasma->canMoveDown = true;


                }
                if (protoFantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    this->protoFantasma->isMovingDown) {
                    protoFantasma->canMoveDown = false;
                    protoFantasma->canMoveUp = true;


                }
                if (protoFantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    this->protoFantasma->isMovingRight) {
                    protoFantasma->canMoveRight = false;
                    protoFantasma->canMoveLeft = true;


                }
                if (protoFantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    this->protoFantasma->isMovingLeft) {
                    protoFantasma->canMoveLeft = false;
                    protoFantasma->canMoveRight = true;


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

    void Game::moveToPowerup() {


        std::cout<<"Posición X PowerUp: "<<this->POWERUPS->head->powerUp->getPos().x<<" Posición Y PowerUp: "<<this->POWERUPS->head->powerUp->getPos().x<<std::endl;

        std::cout<<"Posición X destino: "<<this->protoFantasma->pathToPowerUp.back().x<<" Posición Y destino: "<<this->protoFantasma->pathToPowerUp.back().y<<std::endl;

        if (this->protoFantasma->getPos()== this->protoFantasma->pathToPowerUp[0] ) {
            this->protoFantasma->pathToPowerUp.erase(this->protoFantasma->pathToPowerUp.begin());
            if(this->protoFantasma->pathToPowerUp.empty()){
                this->protoFantasma->isSearching = false;
                this->protoFantasma->isChasing = true;
                this->protoFantasma->isScattering = false;
                pathMade = false;
            }


        } else if (this->protoFantasma->getPos().x > this->protoFantasma->pathToPowerUp[0].x) {
            this->protoFantasma->move(-1.f, 0);
        } else if (this->protoFantasma->getPos().x < this->protoFantasma->pathToPowerUp[0].x) {
            this->protoFantasma->move(1.f, 0);
        } else if (this->protoFantasma->getPos().y > this->protoFantasma->pathToPowerUp[0].y) {
            this->protoFantasma->move(0, -1.f);
        } else if (this->protoFantasma->getPos().y < this->protoFantasma->pathToPowerUp[0].y) {
            this->protoFantasma->move(0, 1.f);
        }

    }

    void Game::updateFantasma() {

        if (this->protoFantasma->getBounds().left < 5) {
            protoFantasma->canMoveLeft = false;
        }
        if (this->protoFantasma->getBounds().left + 65 > 600) {
            protoFantasma->canMoveRight = false;
        }
        if (this->protoFantasma->getBounds().top < 5) {
            protoFantasma->canMoveUp = false;
        }
        if (this->protoFantasma->getBounds().top + 65 > 600) {
            protoFantasma->canMoveDown = false;
        }

        if (this->protoFantasma->isChasing) {
            if (protoFantasma->getPos().x > playerPos.x && protoFantasma->canMoveLeft) {

                this->protoFantasma->isMovingLeft = true;
                this->protoFantasma->isMovingDown = false;
                this->protoFantasma->isMovingUp = false;
                this->protoFantasma->isMovingRight = false;
                this->protoFantasma->canMoveRight = true;


                protoFantasma->move(-1.f, 0.f);

            } else if (protoFantasma->getPos().x < playerPos.x && protoFantasma->canMoveRight) {
                this->protoFantasma->isMovingRight = true;
                this->protoFantasma->isMovingDown = false;
                this->protoFantasma->isMovingUp = false;
                this->protoFantasma->isMovingLeft = false;

                this->protoFantasma->canMoveLeft = true;

                protoFantasma->move(1.f, 0.f);


            } else if (protoFantasma->getPos().y > playerPos.y && protoFantasma->canMoveUp) {
                this->protoFantasma->isMovingUp = true;
                this->protoFantasma->isMovingDown = false;
                this->protoFantasma->isMovingRight = false;
                this->protoFantasma->isMovingLeft = false;


                this->protoFantasma->canMoveDown = true;


                protoFantasma->move(0, -1.f);

            } else if (protoFantasma->getPos().y < playerPos.y && protoFantasma->canMoveDown) {
                this->protoFantasma->isMovingDown = true;
                this->protoFantasma->isMovingUp = false;
                this->protoFantasma->isMovingRight = false;
                this->protoFantasma->isMovingLeft = false;

                this->protoFantasma->canMoveUp = true;


                protoFantasma->move(0, 1.f);


            }
            if (protoFantasma->getBounds().intersects(this->player->getBounds())) {
                respawnPlayer();
                this->liveCounter--;


            }


        } else if (this->protoFantasma->isScattering) {

            //condicones de scatter
        } else if (this->protoFantasma->isSearching) {

            if (!pathMade) {

                std::vector<sf::Vector2f> path = Astar(this->protoFantasma->getPos(),
                                                       this->POWERUPS->head->powerUp->getPos());

                for(auto node:path){
                    std::cout<<"Posición X:"<<node.x<<" Posición Y:"<<node.y<<std::endl;
                }
                protoFantasma->pathToPowerUp = path;

                pathMade = true;
            }

            moveToPowerup();

        }


    }


    void Game::update() {

        this->updatePollEvents();
        this->updateInput();
        this->updatePlayerPos();
        this->updatePoints();
        this->updatePowerUps();
        this->updateFantasma();
        this->updateMap();

        this->updateText();


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

