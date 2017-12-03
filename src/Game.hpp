#ifndef PACWOMAN_GAME_HPP
#define PACWOMAN_GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
private:
    sf::RenderWindow m_window;
};

#endif