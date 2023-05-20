//
// Created by vortizc on 5/8/23.
//

#ifndef PROYECTO2DATOSII_POWERUP_H
#define PROYECTO2DATOSII_POWERUP_H

#include <SFML/Graphics.hpp>
//Clase de Power Up de juego
class PowerUp {
public:
    //constructor
    PowerUp();
    //destructor
    virtual ~PowerUp();
    //getter de posición
    const sf::Vector2f &getPos() const;
    //getter de bordes globales del powerup
    const sf::FloatRect getBounds() const;
    //setter de posición de powerup
    void setPosition(float x, float y);
    //función de renderizacion de powerup
    void renderPowerUp(sf::RenderTarget &target);
    //textura del powerup
    sf::CircleShape circulo;
private:
    //posición x y y del círculo
    float xPos;
    float yPos;
    //inicializador de textura
    void initTexture();
};


#endif //PROYECTO2DATOSII_POWERUP_H
