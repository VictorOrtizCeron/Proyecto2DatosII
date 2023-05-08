//
// Created by vortizc on 5/8/23.
//

#include "PointLinkedList.h"

PointLinkedList::PointLinkedList() {
    this->head = nullptr;
    size = 0;
}

void PointLinkedList::addFirst(Point *point) {

    PointNode *newNode = new PointNode(point);
    if (head == nullptr) {
        this->head = newNode;
    } else {
        newNode->nextPoint = this->head;
        this->head = newNode;

    }
    size++;
}

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

void PointLinkedList::renderPointList(sf::RenderTarget& target) {

    PointNode * current = this-> head;
    while(current != nullptr){
        target.draw(current->point->circulo);
        current = current->nextPoint;
    }
}