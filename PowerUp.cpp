//
// Created by vortizc on 5/8/23.
//

#include "PowerUp.h"
//constructor
PowerUp::PowerUp(){
    this->initTexture();
    this->xPos = 0;
    this->yPos = 0;

}
//destructor
PowerUp::~PowerUp() {

}
//inicializador de textura de powerup
void PowerUp::initTexture() {
    circulo.setRadius(10.f);
    circulo.setFillColor(sf::Color::Yellow);
    circulo.setPosition(xPos,yPos);

}
//getter de posición
const sf::Vector2f &PowerUp::getPos() const {
    return this->circulo.getPosition();
}
//getter de bordes globales
const sf::FloatRect PowerUp::getBounds() const {
    return this->circulo.getGlobalBounds();
}
//render de powerup
void PowerUp::renderPowerUp(sf::RenderTarget &target) {
    target.draw(this->circulo);
}
//setter de posición de powerup
void PowerUp::setPosition(float x, float y) {
    this->yPos = y;
    this->xPos = x;
    this->circulo.setPosition(xPos,yPos);
}