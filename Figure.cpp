//
// Created by moyak on 25.04.2022.
//
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>
#include "Figure.h"
#include "Strenght.h"
using namespace sf;


Figure::Figure(Shape& shape1, bool concrete, double mass): trenie(0, 0 ),
tyazest(0, 0),
reactionOfOpora(0, 0)
{
    this->mass = mass;
    this->shape = &shape1;
    this->isConcrete = concrete;

}


