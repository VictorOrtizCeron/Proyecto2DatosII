#include <SFML/Graphics.hpp>
#include "Game.h"

int main(){

    std::srand(std::time(nullptr));
    Game juego;
    juego.run();
    return 0;
}