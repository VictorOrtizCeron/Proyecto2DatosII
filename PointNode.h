//
// Created by vortizc on 5/8/23.
//

#ifndef PROYECTO2DATOSII_POINTNODE_H
#define PROYECTO2DATOSII_POINTNODE_H

#include "Point.h"

class PointNode {
public:
    PointNode();

    PointNode(Point *punto);

    virtual ~PointNode();

    PointNode *nextPoint{};//puntero a proximo elemento de la lista
    Point *point{};//puntero al objeto Bullet correspondiente
};


#endif //PROYECTO2DATOSII_POINTNODE_H
