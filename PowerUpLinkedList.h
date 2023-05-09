//
// Created by vortizc on 5/9/23.
//

#ifndef PROYECTO2DATOSII_POWERUPLINKEDLIST_H
#define PROYECTO2DATOSII_POWERUPLINKEDLIST_H

#include "PowerUp.h"
#include "PowerUpNode.h"
class PowerUpLinkedList {
public:
    PowerUpLinkedList();
    ~PowerUpLinkedList();
    void addFirst(PowerUp*powerUp);
    PowerUp * removePowerUp(PowerUp * powerToRemove);
    void removeFirst();
    int size;
    PowerUpNode * head;
    void renderPowerUpList(sf::RenderTarget& target);
};


#endif //PROYECTO2DATOSII_POWERUPLINKEDLIST_H
