//
// Created by vortizc on 4/29/23.
//
#include <SFML/Graphics.hpp>
#ifndef PROYECTO2DATOSII_PLAYER_H
#define PROYECTO2DATOSII_PLAYER_H


class Player {
public:
    Player();
    virtual ~Player();
    const sf::Vector2f& getPos() const;
    void setPosition(float x, float y);
    const  sf::FloatRect getBounds() const;
    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);
    bool isMovingUp ;
    bool isMovingDown ;
    bool isMovingLeft ;
    bool isMovingRight ;
    bool canMoveUp ;
    bool canMoveDown ;
    bool canMoveLeft ;
    bool canMoveRight ;
    bool collisionTop;
    bool collisionBot;
    bool collisionLeft;
    bool collisionRight;

private:
    sf::CircleShape circulo;

    float movementSpeed;
    void initVariables();
    void initTexture();

};


#endif //PROYECTO2DATOSII_PLAYER_H
