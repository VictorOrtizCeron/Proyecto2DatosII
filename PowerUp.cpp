//
// Created by vortizc on 5/8/23.
//

#include "PowerUp.h"

PowerUp::PowerUp(){
    this->initTexture();
    this->xPos = 0;
    this->yPos = 0;

}

PowerUp::~PowerUp() {

}
void PowerUp::initTexture() {
    circulo.setRadius(10.f);
    circulo.setFillColor(sf::Color::Yellow);
    circulo.setPosition(xPos,yPos);

}
const sf::Vector2f &PowerUp::getPos() const {
    return this->circulo.getPosition();
}
const sf::FloatRect PowerUp::getBounds() const {
    return this->circulo.getGlobalBounds();
}
void PowerUp::render(sf::RenderTarget &target) {
    target.draw(this->circulo);
}
void PowerUp::setPosition(float x, float y) {
    this->yPos = y;
    this->xPos = x;
    this->circulo.setPosition(xPos,yPos);
}