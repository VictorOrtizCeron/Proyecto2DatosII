#include <SFML/Graphics.hpp>
#include "Game.h"
#include <ctime>
int main(){
    std::srand(std::time(nullptr));

    Game juego;
    juego.run();
    return 0;
}