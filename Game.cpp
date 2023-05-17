//
// Created by vortizc on 4/28/23.
//

#include <stack>
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


    this->TILE_SIZE = 60;
    if(this->levelCounter == 1) {
        this->POINTS = new PointLinkedList();
        int tileMap[10][10] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
    if(this->levelCounter == 2) {
        PointNode* current = this->POINTS->head;
        while( current != nullptr){
           this->POINTS->removeFirst();
           current = current->nextPoint;
        }
        int tileMap[10][10] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


        };
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                TILE_MAP[y][x].setFillColor(sf::Color::Black);

                TILE_MAP[y][x].setOutlineThickness(0);
            }
        }

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
    if(this->levelCounter == 3) {
        PointNode* current = this->POINTS->head;
        while( current != nullptr){
            this->POINTS->removeFirst();
            current = current->nextPoint;
        }
        int tileMap[10][10] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


        };
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                TILE_MAP[y][x].setFillColor(sf::Color::Black);
                TILE_MAP[y][x].setOutlineThickness(0);
            }
        }

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
    if(this->levelCounter == 4) {
        PointNode* current = this->POINTS->head;
        while( current != nullptr){
            this->POINTS->removeFirst();
            current = current->nextPoint;
        }
        int tileMap[10][10] = {
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


        };
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                TILE_MAP[y][x].setFillColor(sf::Color::Black);
                TILE_MAP[y][x].setOutlineThickness(0);
            }
        }

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


void Game::initFantasmas() {

    for (int i = 0; i < 2; i++) {

        Fantasma *newGhost = new Fantasma(i + 1);
        if (i == 0) {
            newGhost->circulo.setPosition(540, 540);
        }
        if (i == 1) {
            newGhost->circulo.setPosition(60, 540);
        }
        this->fantasmas.push_back(newGhost);
    }


}

void Game::initPowerUpList() {
    this->POWERUPS = new PowerUpLinkedList();
}

Game::Game() {
    this->initWindow();

    this->initPlayer();
    this->initFantasmas();
    levelCounter = 1;
    this->initMap();
    this->initPowerUpList();
    this->initText();

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

    if (TILE_MAP[y][x].getFillColor() == sf::Color::Black &&
        !this->player->getBounds().intersects(TILE_MAP[y][x].getGlobalBounds())) {

        PowerUp *newPowerUp = new PowerUp();
        newPowerUp->setPosition(this->TILE_SIZE * x + 20, this->TILE_SIZE * y + 20);

        POWERUPS->addFirst(newPowerUp);
        for (auto &fantasma: fantasmas) {

            fantasma->isSearching = true;
            fantasma->isChasing = false;
            fantasma->isScattering = false;
        }


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
        for (auto &fantasma: this->fantasmas) {
            if (current->powerUp->getBounds().intersects(this->player->getBounds())) {
                PowerUp *powerUpPTR = POWERUPS->removePowerUp(current->powerUp);
                for (auto &ghost: fantasmas) {
                    ghost->isSearching = false;
                    ghost->isChasing = true;
                    ghost->isScattering = false;
                    ghost->pathMade = false;
                }


                delete powerUpPTR;
            }
            if (current->powerUp->getBounds().intersects(fantasma->getBounds())) {
                PowerUp *powerUpPTR = POWERUPS->removePowerUp(current->powerUp);

                for (auto &ghost: fantasmas) {
                    ghost->isSearching = false;
                    ghost->isChasing = true;
                    ghost->isScattering = false;
                    ghost->pathMade = false;
                }

                delete powerUpPTR;


            }
        }
        current = current->nextPowerUp;
    }

}

void Game::updateLevel() {
    if (this->POINTS->head == nullptr) {
        this->levelCounter ++;

        initMap();
        this->player->setPosition(60,60);

    }
}

std::vector<sf::Vector2f> Game::Astar(sf::Vector2f start, sf::Vector2f finish) {

    //Se define vector de camino para retornar
    std::vector<sf::Vector2f> path;
    //Se definen las listas abierta y cerrada
    std::vector<Node *> openList;
    std::vector<Node *> closedList;


    Node *startNode = new Node{getIndex(start),
                               0,
                               manhattanDist(start, finish),
                               0,
                               nullptr};
    Node *endNode = new Node{getIndex(finish), 0, 0, 0, nullptr};

    //Se agrega nodo inicial a openList

    openList.push_back(startNode);
    //std::cout << openList[0]->h << std::endl;
    while (!openList.empty()) {
        //se busca el indice del nodo con menor distancia manhattan
        int lowestIndex = 0;

        for (int i = 0; i < openList.size(); i++) {
            if (openList[i]->F < openList[lowestIndex]->F) {
                lowestIndex = i;
            }
        }

        //se establece el nodo en el cual se realizaran las comparaciones (los pasos de las flechitas)
        Node *currentNode = openList[lowestIndex];

        //se evalúa si el nodo esta a la par del nodo de destino
        if (currentNode->H == endNode->H) {
            Node *node = currentNode;
            while (node != nullptr) {


                //se inserta en la lista de camino
                path.push_back(sf::Vector2f(node->tilePosition[0] * 60, node->tilePosition[1] * 60));
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
                int xPos = currentNode->tilePosition[0] + x;
                int yPos = currentNode->tilePosition[1] + y;

                // Ignore positions outside the map
                if (xPos < 0 || xPos > 9 || yPos < 0 || yPos > 9) {
                    continue;
                }
                //ignora celdas fuera del mapa
                if (this->TILE_MAP[yPos][xPos].getFillColor() == sf::Color::Transparent) {
                    continue;
                }
                // Create the successor node
                std::vector<int> newNodePos = {xPos, yPos};

                sf::Vector2f position = sf::Vector2f(newNodePos[0] * 60, newNodePos[1] * 60);
                Node *successor = new Node{newNodePos,
                                           currentNode->G + 10,
                                           manhattanDist(position, finish),
                                           currentNode->G + 10 + manhattanDist(position, finish),
                                           currentNode};

                //Checkea si el nodo ya esta en alguna de las listas
                bool inClosedList = false;
                for (Node *closedNode: closedList) {
                    if (closedNode->tilePosition[0] == successor->tilePosition[0] &&
                        closedNode->tilePosition[1] == successor->tilePosition[1]) {
                        inClosedList = true;

                        break;
                    }
                }
                if (inClosedList) {
                    continue;
                }

                bool inOpenList = false;
                for (Node *openNode: openList) {
                    if (openNode->tilePosition[0] == successor->tilePosition[0] &&
                        openNode->tilePosition[1] == successor->tilePosition[1]) {
                        inOpenList = true;
                        break;
                    }
                }
                if (!inOpenList) {
                    // Se inserta en la open list
                    openList.push_back(successor);
                } else {
                    // Si el nodo sucesor ya esta en la open list, se revisa si su distancia manhattan es menor
                    for (Node *openNode: openList) {
                        if (openNode->tilePosition[0] == successor->tilePosition[0] &&
                            openNode->tilePosition[1] == successor->tilePosition[1]) {
                            if (successor->F < openNode->F) {
                                openNode->F = successor->F;
                                openNode->parent = currentNode;
                            } else { delete successor; }
                            break;
                        }
                    }

                }
            }

        }
    }


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

std::vector<sf::Vector2f> Game::Backtracking(sf::Vector2f start, sf::Vector2f finish) {
    std::vector startIndex = getIndex(start);
    std::vector endIndex = getIndex(finish);

    std::vector<sf::Vector2f> path;


    NodeBacktrack *startNode = new NodeBacktrack{startIndex, nullptr};
    NodeBacktrack *endNode = new NodeBacktrack{endIndex, nullptr};

    std::vector<NodeBacktrack *> visitedIndexes;
    std::stack<NodeBacktrack *> toBeVisited;

    toBeVisited.push(startNode);

    while (!toBeVisited.empty()) {


        std::vector<NodeBacktrack *> successors;

        NodeBacktrack *currentNode = toBeVisited.top();

        toBeVisited.pop();
        //condición finalización de bucle si se encuentra un camino
        if (currentNode->tilePosition == endNode->tilePosition) {
            NodeBacktrack *node = currentNode;
            while (node != nullptr) {


                //se inserta en la lista de camino
                path.insert(path.begin(), sf::Vector2f(node->tilePosition[0] * 60, node->tilePosition[1] * 60));
                node = node->parent;
            }
            //se da vuelta a lista de camino para que vaya desde inicio a fin
            //std::reverse(path.begin(), path.end());
            //se termina el bucle

            break;
        }

        for (int y = -1; y <= 1; y++) {
            for (int x = -1; x <= 1; x++) {

                //ignora el caso diagonal
                if (x != 0 && y != 0) {

                    continue;
                }
                int succesorIndexX = currentNode->tilePosition[0] + x;
                int succesorIndexY = currentNode->tilePosition[1] + y;



                // Ignora posiciones fuera del mapa
                if (succesorIndexX * 60 < 0 || succesorIndexX * 60 > 540 || succesorIndexY < 0 ||
                    succesorIndexY * 60 > 540) {

                    continue;
                }
                //ignora obstáculos
                if (this->TILE_MAP[succesorIndexY][succesorIndexX].getFillColor() == sf::Color::Transparent) {

                    continue;
                }


                std::vector succesorNodeVec = {succesorIndexX, succesorIndexY};

                NodeBacktrack *successor = new NodeBacktrack{succesorNodeVec, currentNode};

                //Checkea si el nodo ya fue visitado
                bool visited = false;
                for (NodeBacktrack *stackNode: visitedIndexes) {
                    if (stackNode->tilePosition[0] == successor->tilePosition[0] &&
                        stackNode->tilePosition[1] == successor->tilePosition[1]) {
                        visited = true;
                        delete successor;
                        break;
                    }
                }
                if (visited) {

                    continue;
                } else { successors.push_back(successor); }


            }
            for (auto &node: successors) {
                toBeVisited.push(node);
            }
        }
        visitedIndexes.push_back(currentNode);
    }


    return path;

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
            for (auto &fantasma: fantasmas) {
                if (fantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    fantasma->isMovingUp) {
                    fantasma->canMoveUp = false;
                    fantasma->canMoveDown = true;


                }
                if (fantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    fantasma->isMovingDown) {
                    fantasma->canMoveDown = false;
                    fantasma->canMoveUp = true;


                }
                if (fantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    fantasma->isMovingRight) {
                    fantasma->canMoveRight = false;
                    fantasma->canMoveLeft = true;


                }
                if (fantasma->getBounds().intersects(bounds) &&
                    color == sf::Color::Transparent &&
                    fantasma->isMovingLeft) {
                    fantasma->canMoveLeft = false;
                    fantasma->canMoveRight = true;


                }
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

void Game::moveToPowerup(Fantasma *fantasma) {


    if (fantasma->getPos() == fantasma->pathToPowerUp[0]) {

        fantasma->pathToPowerUp.erase(fantasma->pathToPowerUp.begin());

        if (fantasma->pathToPowerUp.empty()) {
            fantasma->isSearching = false;
            fantasma->isChasing = true;
            fantasma->isScattering = false;
            fantasma->pathMade = false;
        }


    } else if (fantasma->getPos().x > fantasma->pathToPowerUp[0].x) {
        fantasma->move(-1.f, 0);
    } else if (fantasma->getPos().x < fantasma->pathToPowerUp[0].x) {
        fantasma->move(1.f, 0);
    } else if (fantasma->getPos().y > fantasma->pathToPowerUp[0].y) {
        fantasma->move(0, -1.f);
    } else if (fantasma->getPos().y < fantasma->pathToPowerUp[0].y) {
        fantasma->move(0, 1.f);
    }


}


void Game::updateFantasmas() {

    for (auto &fantasma: this->fantasmas) {
        if (fantasma->getBounds().left < 5) {
            fantasma->canMoveLeft = false;
        }
        if (fantasma->getBounds().left + 65 > 600) {
            fantasma->canMoveRight = false;
        }
        if (fantasma->getBounds().top < 5) {
            fantasma->canMoveUp = false;
        }
        if (fantasma->getBounds().top + 65 > 600) {
            fantasma->canMoveDown = false;
        }

        if (fantasma->isChasing) {
            if (fantasma->getPos().x > playerPos.x && fantasma->canMoveLeft) {

                fantasma->isMovingLeft = true;
                fantasma->isMovingDown = false;
                fantasma->isMovingUp = false;
                fantasma->isMovingRight = false;
                fantasma->canMoveRight = true;


                fantasma->move(-1.f, 0.f);

            } else if (fantasma->getPos().x < playerPos.x && fantasma->canMoveRight) {
                fantasma->isMovingRight = true;
                fantasma->isMovingDown = false;
                fantasma->isMovingUp = false;
                fantasma->isMovingLeft = false;

                fantasma->canMoveLeft = true;

                fantasma->move(1.f, 0.f);


            } else if (fantasma->getPos().y > playerPos.y && fantasma->canMoveUp) {
                fantasma->isMovingUp = true;
                fantasma->isMovingDown = false;
                fantasma->isMovingRight = false;
                fantasma->isMovingLeft = false;


                fantasma->canMoveDown = true;


                fantasma->move(0, -1.f);

            } else if (fantasma->getPos().y < playerPos.y && fantasma->canMoveDown) {
                fantasma->isMovingDown = true;
                fantasma->isMovingUp = false;
                fantasma->isMovingRight = false;
                fantasma->isMovingLeft = false;

                fantasma->canMoveUp = true;


                fantasma->move(0, 1.f);


            }
            if (fantasma->getBounds().intersects(this->player->getBounds())) {
                //respawnPlayer();
                this->liveCounter--;


            }


        } else if (fantasma->isScattering) {

            //condicones de scatter
        } else if (fantasma->isSearching) {

            if (!fantasma->pathMade) {


                if (fantasma->Type == 1) {
                    //fanstama ROJO usa Backtracking
                    std::vector<sf::Vector2f> path = Backtracking(fantasma->getPos(),
                                                                  this->POWERUPS->head->powerUp->getPos());
                    fantasma->pathToPowerUp = path;
                    std::cout << "Posición X Fantasma " << fantasma->getPos().x / 60 << " Posición Y Fantasma "
                              << fantasma->getPos().y / 60 << std::endl;
                    for (auto &node: path) {
                        std::cout << "Posición X " << node.x / 60 << " Posición Y " << node.y / 60 << std::endl;
                    }
                }
                if (fantasma->Type == 2) {
                    //fantasma Verde usa A estrella
                    std::vector<sf::Vector2f> path = Astar(fantasma->getPos(),
                                                           this->POWERUPS->head->powerUp->getPos());

                    //std::vector<sf::Vector2f> path = Backtracking(fantasma->getPos(),
                    //                                             this->POWERUPS->head->powerUp->getPos());
                    fantasma->pathToPowerUp = path;


                }


                fantasma->pathMade = true;


                //continue;
            }

            moveToPowerup(fantasma);

        }

    }

}

std::vector<int> Game::getIndex(sf::Vector2f pos) {

    int X = pos.x / 60;
    int Y = pos.y / 60;

    std::vector<int> indexes = {X, Y};
    return indexes;
}

void Game::update() {

    this->updatePollEvents();
    this->updateInput();
    this->updatePlayerPos();
    this->updatePoints();
    this->updatePowerUps();
    this->updateFantasmas();
    this->updateMap();

    this->updateText();


}

void Game::renderFantasmas() {
    for (auto &fantasma: this->fantasmas) {
        fantasma->render(*this->window);
    }
}

void Game::render() {

    this->window->clear();
    this->updateLevel();

    this->renderMap();
    this->renderText();

    this->POINTS->renderPointList(*this->window);
    this->POWERUPS->renderPowerUpList(*this->window);

    this->player->render(*this->window);

    this->renderFantasmas();

    this->window->display();

}

void Game::run() {

    while (this->window->isOpen()) {
        this->update();
        this->render();

    }

}

