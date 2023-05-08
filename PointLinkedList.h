//
// Created by vortizc on 5/8/23.
//

#ifndef PROYECTO2DATOSII_POINTLINKEDLIST_H
#define PROYECTO2DATOSII_POINTLINKEDLIST_H
#include "Point.h"
#include "PointNode.h"
#include <SFML/Graphics.hpp>
class PointLinkedList {
public:
    PointLinkedList();
    ~PointLinkedList();
    void addFirst(Point * point);
    void removePoint(Point * pointToRemove);
    void removeFirst();
    int size;
    PointNode * head;
    void renderPointList(sf::RenderTarget& target);
};


#endif //PROYECTO2DATOSII_POINTLINKEDLIST_H
