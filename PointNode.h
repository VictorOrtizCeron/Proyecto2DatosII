//
// Created by vortizc on 5/8/23.
//

#ifndef PROYECTO2DATOSII_POINTNODE_H
#define PROYECTO2DATOSII_POINTNODE_H

#include "Point.h"
//clase de nodo de punto en mapa
class PointNode {
public:
    PointNode();

    PointNode(Point *punto);

    virtual ~PointNode();

    PointNode *nextPoint;
    Point *point;
};


#endif //PROYECTO2DATOSII_POINTNODE_H
