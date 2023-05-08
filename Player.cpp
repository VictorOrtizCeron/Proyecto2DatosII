//
// Created by vortizc on 4/29/23.
//

#include <iostream>
#include "Player.h"

void Player::initVariables()
{
    this->movementSpeed = 3.f;

}
Player::Player(){
    this->initVariables();
    this->initTexture();
    this->initVariables();

}
Player::~Player() {

}
void Player::initTexture() {
    circulo.setRadius(30.f);
    circulo.setFillColor(sf::Color::Yellow);
    circulo.setPosition(400.f-50.f,400.f-50.f);

}

void Player::move(const float dirX, const float dirY) {

    this->circulo.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}
const sf::Vector2f&Player::getPos()const
{
    return this->circulo.getPosition();
}
//funcion que retorna los bordes globales de la nave principal
const sf::FloatRect Player::getBounds() const
{
    return this->circulo.getGlobalBounds();
}
void Player::update() {
    std::cout<<"hace update"<<std::endl;
}
void Player::render(sf::RenderTarget& target)
{
    target.draw(this->circulo);
}