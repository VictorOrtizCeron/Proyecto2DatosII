//
// Created by vortizc on 5/8/23.
//

#ifndef PROYECTO2DATOSII_POWERUP_H
#define PROYECTO2DATOSII_POWERUP_H

#include <SFML/Graphics.hpp>
class PowerUp {
public:
    PowerUp();

    virtual ~PowerUp();

    const sf::Vector2f &getPos() const;

    const sf::FloatRect getBounds() const;

    void setPosition(float x, float y);

    void renderPowerUp(sf::RenderTarget &target);

    sf::CircleShape circulo;
private:

    float xPos;
    float yPos;
    void initTexture();
};


#endif //PROYECTO2DATOSII_POWERUP_H
