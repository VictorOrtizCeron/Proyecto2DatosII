//
// Created by vortizc on 5/9/23.
//

#include "PowerUpNode.h"
//constructor de PowerUpNode
PowerUpNode::PowerUpNode() {

}
//constructor de PowerUpNode sobrecargado
PowerUpNode::PowerUpNode(PowerUp*powerUp) {
    this->powerUp = powerUp;
    this->nextPowerUp= nullptr;
}
//destructor de PowerUpNode
PowerUpNode::~PowerUpNode() = default;