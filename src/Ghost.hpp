//
// Created by Eloy Hernandez on 06/12/17.
//

#ifndef PAC_WOMAN_GHOST_HPP
#define PAC_WOMAN_GHOST_HPP


#include "Character.hpp"

class Ghost : public Character
{
public:
    enum State
    {
        Strong,
        Weak
    };

public:
    Ghost(sf::Texture texture);
    void setWeak(sf::Time duration);
    bool isWeak() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;

    bool m_isWeak;
    sf::Time m_weaknessDuration;
    sf::Sprite m_visual;
};


#endif //PAC_WOMAN_GHOST_HPP
