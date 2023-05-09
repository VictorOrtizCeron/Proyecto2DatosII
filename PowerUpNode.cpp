//
// Created by vortizc on 5/9/23.
//

#include "PowerUpNode.h"

PowerUpNode::PowerUpNode() {

}

PowerUpNode::PowerUpNode(PowerUp*powerUp) {
    this->powerUp = powerUp;
    this->nextPowerUp= nullptr;
}

PowerUpNode::~PowerUpNode() = default;