//
// Created by Eloy Hernandez on 06/12/17.
//

#ifndef PAC_WOMAN_CHARACTER_HPP
#define PAC_WOMAN_CHARACTER_HPP

#include <SFML/Graphics.hpp>

class Character : public sf::Drawable, public sf::Transformable
{
public:
    Character();
    void setSpeed(float speed);
    float getSpeed() const;

private:
    float m_speed;
};


#endif //PAC_WOMAN_CHARACTER_HPP
