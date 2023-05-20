//
// Created by vortizc on 5/8/23.
//


#ifndef PROYECTO2DATOSII_POINTLINKEDLIST_H
#define PROYECTO2DATOSII_POINTLINKEDLIST_H
#include "Point.h"
#include "PointNode.h"
#include <SFML/Graphics.hpp>

//clase de lista enlazada para puntos de juego
class PointLinkedList {
public:

    PointLinkedList();
    ~PointLinkedList();
    //método que agrega un punto a la lista
    void addFirst(Point * point);
    //método que elimina un punto de la lista
    Point* removePoint(Point * pointToRemove);
    //método que elimina el primer punto de la lista
    void removeFirst();
    //tamaño de la lista
    int size;
    //cabecera de la lista
    PointNode * head;
    //función de renderización de la lista enlazada
    void renderPointList(sf::RenderTarget& target);
};


#endif //PROYECTO2DATOSII_POINTLINKEDLIST_H
