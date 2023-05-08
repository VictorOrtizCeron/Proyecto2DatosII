//
// Created by vortizc on 5/8/23.
//

#include "PointNode.h"

PointNode::PointNode() {

}

PointNode::PointNode(Point*punto) {
    this->point = punto;
    this->nextPoint = nullptr;
}

PointNode::~PointNode() = default;