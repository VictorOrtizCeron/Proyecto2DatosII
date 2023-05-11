//
// Created by vortizc on 5/9/23.
//

#include "Fantasma.h"


Fantasma::Fantasma(int type) {
    this->initVariables();
    this->Type = type;
    this->initTexture(this->Type);
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    isMovingDown = false;
    canMoveUp = true;
    canMoveDown = true;
    canMoveLeft = true;
    canMoveRight = true;


}

Fantasma::~Fantasma() {

}
void Fantasma::initVariables()
{
    this->movementSpeed = 2.f;
}
void Fantasma::initTexture(int type) {

    circulo.setRadius(30.f);

    if(type == 1){
        circulo.setFillColor(sf::Color::Red);
    }
    if(type == 2){
        circulo.setFillColor(sf::Color::Green);
    }
    if(type == 3){
        circulo.setFillColor(sf::Color::Cyan);
    }
    if(type == 4){
        circulo.setFillColor(sf::Color::Blue);
    }

    circulo.setPosition(400.f-50.f,400.f-50.f);

}
const sf::Vector2f&Fantasma::getPos()const
{
    return this->circulo.getPosition();
}
//funcion que retorna los bordes globales de la nave principal
const sf::FloatRect Fantasma::getBounds() const
{
    return this->circulo.getGlobalBounds();
}
void Fantasma::render(sf::RenderTarget& target)
{
    target.draw(this->circulo);
}
void Fantasma::move(const float dirX, const float dirY) {

    this->circulo.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}