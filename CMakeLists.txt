cmake_minimum_required(VERSION 3.24)
project(Proyecto2DatosII)

set(CMAKE_CXX_STANDARD 17)
set(SFML_INCLUDE_DIR "/home/vortizc/Downloads/SFML-2.5.1-linux-gcc-64-bit/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/vortizc/Downloads/SFML-2.5.1-linux-gcc-64-bit/SFML-2.5.1/lib")
set(SFML_DIR "/home/vortizc/Downloads/SFML-2.5.1-linux-gcc-64-bit/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)


if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Proyecto2DatosII main.cpp Game.cpp Game.h Player.cpp Player.h Point.cpp Point.h PointNode.cpp PointNode.h PointLinkedList.cpp PointLinkedList.h PowerUp.cpp PowerUp.h PowerUpNode.cpp PowerUpNode.h PowerUpLinkedList.cpp PowerUpLinkedList.h Fantasma.cpp Fantasma.h)
target_link_libraries (Proyecto2DatosII sfml-graphics sfml-window sfml-system)
