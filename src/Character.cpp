//
// Created by Eloy Hernandez on 06/12/17.
//

#include "Character.hpp"

Character::Character()
: m_speed(1.f)
{}

float Character::getSpeed() const {
    return m_speed;
}

void Character::setSpeed(float speed) {
    m_speed = speed;
}


