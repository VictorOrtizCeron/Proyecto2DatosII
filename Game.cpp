//
// Created by vortizc on 4/28/23.
//

#include <stack>
#include "Game.h"
//método incializador de ventana
void Game::initWindow() {

    this->window = new sf::RenderWindow(sf::VideoMode(600, 700), "Ventana de Juego");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}
//método inicializador de texto
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

    this->text[3].setFont(this->minecraftFont);
    this->text[3].setString("");
    this->text[3].setCharacterSize(40);
}
//método inicializador de mapas para todos los niveles
void Game::initMap() {


    this->TILE_SIZE = 60;
    //condicional para primer nivel
    if(this->levelCounter == 1) {
        this->POINTS = new PointLinkedList();//inicio de lista enlazada de puntos
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

        //constructor de mapa de objetos tipo sf::RectangleShape
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
    //condicional para segundo nivel
    if(this->levelCounter == 2) {
        PointNode* current = this->POINTS->head;
        //limpieza de lista enlazada de puntos (reinicialización)
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
        //constructor de mapa de objetos tipo sf::RectangleShape
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
    //condicional para tercer nivel
    if(this->levelCounter == 3) {
        PointNode* current = this->POINTS->head;
        //limpieza de lista enlazada de puntos (reinicialización)
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
        //constructor de mapa de objetos tipo sf::RectangleShape
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
    //condicional para cuarto nivel
    if(this->levelCounter == 4) {
        PointNode* current = this->POINTS->head;
        //limpieza de lista enlazada de puntos (reinicialización)
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
        //constructor de mapa de objetos tipo sf::RectangleShape
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
    //condicional de fin de juego
    if(this->levelCounter == 5) {
        this->gameOver = true;
        this->text[3].setString("Game OVER");

        this->text[3].setPosition(180,200);
        this->text[1].setPosition(180,160);
    }

}
//renderizador de mapap
void Game::renderMap() {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            this->window->draw(this->TILE_MAP[y][x]);
        }
    }
}
//inicializador de jugador
void Game::initPlayer() {
    this->player = new Player();
    this->playerPos = player->getPos();
}
//inicializador de vector de fantasmas
void Game::initFantasmas() {
    //se utiliza el vector de fantasmas. Solo se manejan 2 fantasmas
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
//inicializador de lista enlazada de powerups
void Game::initPowerUpList() {
    this->POWERUPS = new PowerUpLinkedList();
}
//constructor de Game
Game::Game() {
    this->gameOver = false;
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
//destructor de Game
Game::~Game() {
    delete this->window;

}
//actualizador de polling de eventos
void Game::updatePollEvents() {
    sf::Event evento;
    while (this->window->pollEvent(evento)) {
        if (evento.Event::type == sf::Event::Closed)
            this->window->close();
        if (evento.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}
//actualizador de inputs de jugador
void Game::updateInput() {
    //condicion de fin de juego
    if(!gameOver) {
        //reinicio de booleanos de movimiento para detección de colisiones
        this->player->canMoveLeft = true;
        this->player->canMoveRight = true;
        this->player->canMoveUp = true;
        this->player->canMoveDown = true;
        //Detección de bordes de pantalla
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

        //controles de juego
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
        if(liveCounter == 0) {
            this->gameOver = true;
            this->text[3].setString("Game OVER");
            this->text[2].setString("");
            this->text[0].setString("");
            this->text[3].setPosition(180, 200);
            this->text[1].setPosition(180, 160);
        }
    }
}
//funcion regeneradora de jugador al entrar en contacto con fantasma
void Game::respawnPlayer() {
    int x = rand() % 10;
    int y = rand() % 10;
    if (TILE_MAP[y][x].getFillColor() == sf::Color::Black) {
        this->player->setPosition(x * TILE_SIZE, y * TILE_SIZE);

    } else {
        spawnPowerUp();
    }
}
//funcion de generación de power up en mapa
void Game::spawnPowerUp() {

    int x = rand() % 10;
    int y = rand() % 10;

    if (TILE_MAP[y][x].getFillColor() == sf::Color::Black &&
        !this->player->getBounds().intersects(TILE_MAP[y][x].getGlobalBounds())) {

        PowerUp *newPowerUp = new PowerUp();
        newPowerUp->setPosition(this->TILE_SIZE * x + 20, this->TILE_SIZE * y + 20);

        POWERUPS->addFirst(newPowerUp);
        for (auto &fantasma: fantasmas) {
            //activación de modo de búsqueda de fantasmas
            fantasma->isSearching = true;
            fantasma->isChasing = false;
            fantasma->isScattering = false;
        }


    } else {
        spawnPowerUp();
    }

}
//función de update de powerups
void Game::updatePowerUps() {
    //condicionales limitadores de sobrecarga de powerups
    if (pointCounter % 200 == 0 && !spawnedPowerUp) {
        this->spawnPowerUp();
        spawnedPowerUp = true;

    }
    if (pointCounter % 200 != 0 && spawnedPowerUp) {
        spawnedPowerUp = false;
    }
    //inserción de power up en lista enlazada de powerups
    PowerUpNode *current = this->POWERUPS->head;
    //validación de colisiones de jugador con powerup y fantasma con powerup
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
                    ghost->canMoveDown = true;
                    ghost->canMoveUp = true;
                    ghost->canMoveRight = true;
                    ghost->canMoveLeft = true;
                }

                delete powerUpPTR;


            }
        }
        current = current->nextPowerUp;
    }

}
//función actualizadora de nivel
void Game::updateLevel() {
    if (this->POINTS->head == nullptr) {
        this->levelCounter ++;
        initMap();
        this->player->setPosition(60,60);
        int i = 0;
        for(auto &fantasma:fantasmas){

            if( i == 0){
            fantasma->circulo.setPosition(0,540);}
            else{
                fantasma->circulo.setPosition(540,540);
                }
            i++;
        }

    }
}
//Algoritmo A estrella
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
                //posicion del posible sucesor
                int xPos = currentNode->tilePosition[0] + x;
                int yPos = currentNode->tilePosition[1] + y;

                // Ignora todas las posiciones fuera del mapa
                if (xPos < 0 || xPos > 9 || yPos < 0 || yPos > 9) {
                    continue;
                }
                //ignora obstáculos
                if (this->TILE_MAP[yPos][xPos].getFillColor() == sf::Color::Transparent) {
                    continue;
                }
                // Crea nodo sucesor
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

                        delete(successor);
                    }


            }


        }
        std::cout<<std::endl;
        //prints solicitados de open list , closed list y el nodo seleccionado.
        std::cout<< "Nodo Seleccionado:(" << currentNode->tilePosition[0]<<","<<currentNode->tilePosition[1]<<")"<<std::endl;
        std::cout<<"OpenList:";
        for(auto &node:openList){
            std::cout<< " ("<<node->tilePosition[0]<<","<<node->tilePosition[1]<<") ";
        }
        std::cout<<std::endl;
        std::cout<<"closedList:";
        for(auto &node:closedList){
            std::cout<< " ("<<node->tilePosition[0]<<","<<node->tilePosition[1]<<") ";
        }
        std::cout<<std::endl;
    }


    return path;
}
//función auxiliar calculadora de distancia manhattan
int Game::manhattanDist(sf::Vector2f currentPosition, sf::Vector2f finish) {
    int currentX = currentPosition.x / 60;
    int currentY = currentPosition.y / 60;
    int FinishX = finish.x / 60;
    int FinishY = finish.y / 60;
    int h = abs(currentX - FinishX) + abs(currentY - FinishY);
    return h;

}
 //Algoritmo de Backtracking
std::vector<sf::Vector2f> Game::Backtracking(sf::Vector2f start, sf::Vector2f finish) {

    std::vector startIndex = getIndex(start);
    std::vector endIndex = getIndex(finish);

    std::vector<sf::Vector2f> path;


    NodeBacktrack *startNode = new NodeBacktrack{startIndex, nullptr};
    NodeBacktrack *endNode = new NodeBacktrack{endIndex, nullptr};

    std::vector<NodeBacktrack *> visitedIndexes;
    std::stack<NodeBacktrack *> toBeVisited;

    toBeVisited.push(startNode);
    std::cout<<"Comienzo: "<<" (" << startNode->tilePosition[0] << "," << startNode->tilePosition[1] << ") "<<std::endl;

    while (!toBeVisited.empty()) {


        std::vector<NodeBacktrack *> successors;

        NodeBacktrack *currentNode = toBeVisited.top();

        std::cout<<"Seleccionado: "<<" (" << currentNode->tilePosition[0] << "," << currentNode->tilePosition[1] << ") "<<std::endl;
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

        }
        //print de árbol de decisiones
        std::cout<<"Sucesores: ";
        for (auto &node: successors) {
            std::cout << " (" << node->tilePosition[0] << "," << node->tilePosition[1] << ") ";
            toBeVisited.push(node);
        }

        std::stack tempStack = toBeVisited;
        std::cout<<std::endl;
        std::cout<<"Stack: ";
            while (!tempStack.empty()) {
            std::cout << " (" << tempStack.top()->tilePosition[0] << "," << tempStack.top()->tilePosition[1] << ") ";
            tempStack.pop();

        }
        std::cout<<std::endl;
        std::cout<<std::endl;
        visitedIndexes.push_back(currentNode);
    }


    return path;

}
//función de actualización de mapa
void Game::updateMap() {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sf::Color color = this->TILE_MAP[y][x].getFillColor();
            sf::FloatRect bounds = this->TILE_MAP[y][x].getGlobalBounds();
            bounds.width = 65.f;
            bounds.height = 65.f;
            //detección de colisiones de jugador y fantasmas
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
//función actualizadora de puntos
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
//función actualizadora de texto
void Game::updateText() {

    this->text[0].setString("Lives: " + std::to_string(liveCounter));
    this->text[1].setString("Points: " + std::to_string(pointCounter));
    this->text[2].setString("Level: " + std::to_string(levelCounter));
    //condicional de finalización de juego
    if(gameOver){
        this->text[0].setString("" );
        this->text[2].setString("");
    }
}
//funcion de rederización de juego
void Game::renderText() {

    for (int i = 0; i < 4; i++) {
        this->window->draw(text[i]);
    }

}
//funcion de actualización de posición de jugador como parámetro global
void Game::updatePlayerPos() {
    this->playerPos = player->getPos();
}
//función de seguimiento de camino para fantasmas
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
//función de actualización de fantasmas
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
                //this->liveCounter--;


            }


        } else if (fantasma->isScattering) {

            //condicones de scatter

        } else if (fantasma->isSearching) {//condicional de búsqueda de powerup

            if (!fantasma->pathMade) {


                if (fantasma->Type == 1) {
                    //fanstama rojo usa Backtracking
                    std::vector<sf::Vector2f> path = Backtracking(fantasma->getPos(),
                                                                  this->POWERUPS->head->powerUp->getPos());
                    fantasma->pathToPowerUp = path;


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
//función auxiliar para métodos de búsqueda
std::vector<int> Game::getIndex(sf::Vector2f pos) {

    int X = pos.x / 60;
    int Y = pos.y / 60;

    std::vector<int> indexes = {X, Y};
    return indexes;
}
//función de actualización de juego
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
//funcion de rederización de fantasmas
void Game::renderFantasmas() {
    for (auto &fantasma: this->fantasmas) {
        fantasma->render(*this->window);
    }
}
//función de renderización global
void Game::render() {

    this->window->clear();
    this->updateLevel();

    this->renderMap();


    this->POINTS->renderPointList(*this->window);
    this->POWERUPS->renderPowerUpList(*this->window);

    this->player->render(*this->window);

    this->renderFantasmas();
    this->renderText();
    this->window->display();

}
//función que corre la instancia de juego creada en main
void Game::run() {

    while (this->window->isOpen()) {
        this->update();
        this->render();

    }

}

