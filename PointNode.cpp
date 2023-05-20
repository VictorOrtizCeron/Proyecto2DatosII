//
// Created by vortizc on 5/8/23.
//

#include "PointNode.h"
//clase de nodo de punto en mapa
//constructor
PointNode::PointNode() {

}
//constructor sobrecargado
PointNode::PointNode(Point*punto) {
    this->point = punto;
    this->nextPoint = nullptr;
}
//destructor
PointNode::~PointNode() = default;