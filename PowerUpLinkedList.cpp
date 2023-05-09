//
// Created by vortizc on 5/9/23.
//

#include "PowerUpLinkedList.h"

PowerUpLinkedList::PowerUpLinkedList() {
    this->head = nullptr;
    this->size = 0;
}
void PowerUpLinkedList::addFirst(PowerUp *powerUp) {

    PowerUpNode *newNode = new PowerUpNode(powerUp);
    if (head == nullptr) {
        this->head = newNode;
    } else {
        newNode->nextPowerUp = this->head;
        this->head = newNode;

    }
    size++;
}

void PowerUpLinkedList::removeFirst() {

    if(head == nullptr){
        return ;

    }
    else{
        PowerUpNode *Temp = head;
        head= head->nextPowerUp;
        delete Temp;
        size--;
    }
}
PowerUp* PowerUpLinkedList::removePowerUp(PowerUp *powerToRemove) {

    PowerUpNode *current=this->head;
    PowerUpNode * previous = nullptr;

    while(current != nullptr){
        if(current->powerUp == powerToRemove){

            if(previous == nullptr){
                this->head = current->nextPowerUp;

                size--;
                return current->powerUp;

            }
            else{
                previous->nextPowerUp = current->nextPowerUp;

                size--;
                return current->powerUp;
            }
        }
        previous = current;
        current = current->nextPowerUp;
    }
}
void PowerUpLinkedList::renderPowerUpList(sf::RenderTarget& target) {

    PowerUpNode * current = this-> head;
    while(current != nullptr){

        target.draw(current->powerUp->circulo);
        current = current->nextPowerUp;
    }
}