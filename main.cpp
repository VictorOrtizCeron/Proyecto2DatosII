#include <SFML/Graphics.hpp>
#include "Game.h"
//función principal de aplicación
int main(){

    std::srand(std::time(nullptr));
    Game juego;
    juego.run();
    return 0;
}