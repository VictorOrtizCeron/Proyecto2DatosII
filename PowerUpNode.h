//
// Created by vortizc on 5/9/23.
//

#ifndef PROYECTO2DATOSII_POWERUPNODE_H
#define PROYECTO2DATOSII_POWERUPNODE_H
#include "PowerUp.h"
//clase de nodo para powerUp
class PowerUpNode {
public:
    //constructor
    PowerUpNode();
    //constructor sobrecargado
    PowerUpNode(PowerUp *powerUp);
    //desctructor
    virtual ~PowerUpNode();
    //puntero a siguiente PowerUpNode
    PowerUpNode *nextPowerUp;
    //puntero a  PowerUp
    PowerUp *powerUp;
};


#endif //PROYECTO2DATOSII_POWERUPNODE_H
