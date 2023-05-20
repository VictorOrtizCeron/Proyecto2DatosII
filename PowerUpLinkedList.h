//
// Created by vortizc on 5/9/23.
//

#ifndef PROYECTO2DATOSII_POWERUPLINKEDLIST_H
#define PROYECTO2DATOSII_POWERUPLINKEDLIST_H
#include "PowerUp.h"
#include "PowerUpNode.h"
//Clase de lista enlazada de powerUp
class PowerUpLinkedList {
public:
    //constructor
    PowerUpLinkedList();
    //destructor
    ~PowerUpLinkedList();
    //método que agrega power up al inicio de la lista enlazada
    void addFirst(PowerUp*powerUp);
    //método que elimina powerUp esepcífico de la lista enlazada
    PowerUp * removePowerUp(PowerUp * powerToRemove);
    //método que elimina el primer elemento de la lista enlazada
    void removeFirst();
    //tamaño de la lista enlazada
    int size;
    //Cabecera de la lista enlazada
    PowerUpNode * head;
    //función renderizadora de la lista enlazada
    void renderPowerUpList(sf::RenderTarget& target);
};


#endif //PROYECTO2DATOSII_POWERUPLINKEDLIST_H
