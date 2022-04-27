//
// Created by moyak on 25.04.2022.
//
#ifndef ENGINE__FIGURE_H
#define ENGINE__FIGURE_H
#include <SFML/Graphics.hpp>
#include "Strenght.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

class Figure{
public:
    Figure(sf::Shape& shape1, bool concrete, double mass);
    bool isConcrete;
    sf::Shape* shape;
    Strenght trenie;
    Strenght reactionOfOpora;
    Strenght tyazest;
    double speedx = 0;
    double speedy = 0;
    double speedangle = 0;
    double mass;
    double x;
    double y;
    void setXY(double x, double y) {
        this->x = x;
        this->y = y;
    }

};



#endif //ENGINE__FIGURE_H
