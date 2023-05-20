//
// Created by vortizc on 5/8/23.
//

#include "PointLinkedList.h"
//constructor
PointLinkedList::PointLinkedList() {
    this->head = nullptr;
    size = 0;
}
//método que agrega punto a la lista
void PointLinkedList::addFirst(Point *point) {
    //agrega el punto en la cabecera de la lista
    PointNode *newNode = new PointNode(point);
    if (head == nullptr) {
        this->head = newNode;
    } else {
        newNode->nextPoint = this->head;
        this->head = newNode;

    }
    size++;
}
//método que elimina cabecera de la lista enlazada
void PointLinkedList::removeFirst() {

    if(head == nullptr){
        return ;

    }

    else{
        PointNode *Temp = head;
        head= head->nextPoint;
        delete Temp;
        size--;
    }
}
//método que retorna un puntero a un punto específico en la lista para borrar en el runtime de Game
Point* PointLinkedList::removePoint(Point *pointToRemove) {

    PointNode *current=this->head;
    PointNode * previous = nullptr;

    while(current != nullptr){
        if(current->point == pointToRemove){

            if(previous == nullptr){
                this->head = current->nextPoint;

                size--;
                return current->point;

            }
            else{
                previous->nextPoint = current->nextPoint;

                size--;
                return current->point;
            }
        }
        previous = current;
        current = current->nextPoint;
    }
}
//función que renderiza todos los puntos de la lista en el mapa
void PointLinkedList::renderPointList(sf::RenderTarget& target) {

    PointNode * current = this-> head;
    while(current != nullptr){
        target.draw(current->point->circulo);
        current = current->nextPoint;
    }
}