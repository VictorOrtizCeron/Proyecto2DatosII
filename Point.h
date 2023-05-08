//
// Created by vortizc on 5/7/23.
//

#ifndef PROYECTO2DATOSII_POINT_H
#define PROYECTO2DATOSII_POINT_H

#include <SFML/Graphics.hpp>

class Point {
public:

    Point();
    Point(float x, float y);
    virtual ~Point();

    const sf::Vector2f &getPos() const;

    const sf::FloatRect getBounds() const;

    void setPosition(float x, float y);
    void render(sf::RenderTarget &target);
    sf::CircleShape circulo;
private:


    float xPos;
    float yPos;
    void initTexture();


};


#endif //PROYECTO2DATOSII_POINT_H
