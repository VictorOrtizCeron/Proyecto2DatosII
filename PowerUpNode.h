//
// Created by vortizc on 5/9/23.
//

#ifndef PROYECTO2DATOSII_POWERUPNODE_H
#define PROYECTO2DATOSII_POWERUPNODE_H
#include "PowerUp.h"

class PowerUpNode {
public:
    PowerUpNode();

    PowerUpNode(PowerUp *powerUp);

    virtual ~PowerUpNode();

    PowerUpNode *nextPowerUp;
    PowerUp *powerUp;
};


#endif //PROYECTO2DATOSII_POWERUPNODE_H
