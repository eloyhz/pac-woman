//
// Created by Eloy Hernandez on 06/12/17.
//

#ifndef PAC_WOMAN_PACWOMAN_HPP
#define PAC_WOMAN_PACWOMAN_HPP

#include "Character.hpp"

class PacWoman : public Character
{
public:
    PacWoman(sf::Texture& texture);
    void die();
    bool isDead() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;

    bool m_isDead;
    sf::Sprite m_visual;
};


#endif //PAC_WOMAN_PACWOMAN_HPP
