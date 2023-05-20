//
// Created by vortizc on 5/9/23.
//

#ifndef PROYECTO2DATOSII_FANTASMA_H
#define PROYECTO2DATOSII_FANTASMA_H
#include <SFML/Graphics.hpp>

class Fantasma {
public:
    //funciones de control de posición y obtención de datos
    Fantasma(int type);
    virtual ~Fantasma();
    const sf::Vector2f& getPos() const;
    const  sf::FloatRect getBounds() const;
    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);

    sf::CircleShape circulo;
    //booleanos de movimiento para detección de colisiones continua
    bool isMovingLeft;
    bool isMovingRight;
    bool isMovingUp;
    bool isMovingDown;
    bool canMoveUp;
    bool canMoveDown;
    bool canMoveLeft;
    bool canMoveRight;
    bool isChasing;
    bool isSearching;
    bool isScattering;
    bool pathMade;
    //vector de camino asignado hacia powerUp
    std::vector<sf::Vector2f> pathToPowerUp;
    //tipo de fantasma
    int Type;
private:

    float movementSpeed;
    void initVariables();
    void initTexture(int type);

};


#endif //PROYECTO2DATOSII_FANTASMA_H
