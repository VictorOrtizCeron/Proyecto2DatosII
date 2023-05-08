//
// Created by vortizc on 5/7/23.
//


#include "Point.h"

Point::Point() {
    this->initTexture();
    this->xPos = 0;
    this->yPos = 0;

}

Point::Point(float x, float y) {
    this->initTexture();
    this->xPos = x;
    this->yPos = y;

}

Point::~Point() {

}

void Point::initTexture() {
    circulo.setRadius(5.f);
    circulo.setFillColor(sf::Color::Yellow);
    circulo.setPosition(xPos,yPos);

}

const sf::Vector2f &Point::getPos() const {
    return this->circulo.getPosition();
}
void Point::setPosition(float x, float y) {
    this->yPos = y;
    this->xPos = x;
    this->circulo.setPosition(xPos,yPos);
}
const sf::FloatRect Point::getBounds() const {
    return this->circulo.getGlobalBounds();
}

void Point::render(sf::RenderTarget &target) {
    target.draw(this->circulo);
}