//
// Created by Eloy Hernandez on 06/12/17.
//

#ifndef PAC_WOMAN_BONUS_HPP
#define PAC_WOMAN_BONUS_HPP


#include <SFML/Graphics.hpp>

class Bonus : public sf::Drawable, public sf::Transformable
{
public:
    enum Fruit
    {
        Banana,
        Apple,
        Cherry
    };

    Bonus(sf::Texture& texture);
    void setFruit(Fruit fruit);



private:
    sf::Sprite m_visual;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};


#endif //PAC_WOMAN_BONUS_HPP
