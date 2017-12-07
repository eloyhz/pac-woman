//
// Created by Eloy Hernandez on 06/12/17.
//

#include "Dot.hpp"

sf::CircleShape getDot()
{
    sf::CircleShape dot;
    dot.setRadius(4);
    dot.setFillColor(sf::Color::White);
    dot.setOrigin(2, 2);
    return dot;
}

sf::CircleShape getSuperDot()
{
    sf::CircleShape dot;
    dot.setRadius(8);
    dot.setFillColor(sf::Color::White);
    dot.setOrigin(4, 4);
    return dot;
}
