#include "Game.hpp"
#include <iostream>

Game::Game()
:m_window(sf::VideoMode(640, 480), "Pac Woman")
{}

void Game::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::I)
                    insertCoin();
                if (event.key.code == sf::Keyboard::S)
                    pressButton();
                if (event.key.code == sf::Keyboard::Left)
                    moveStick(sf::Vector2i(-1, 0));
                if (event.key.code == sf::Keyboard::Right)
                    moveStick(sf::Vector2i(0, 1));
                if (event.key.code == sf::Keyboard::Up)
                    moveStick(sf::Vector2i(0, -1));
                if (event.key.code == sf::Keyboard::Down)
                    moveStick(sf::Vector2i(0, 1));
            }
        }
        m_window.clear();
        // draw here...
        m_window.display();
    }
}

void Game::insertCoin()
{
    std::cout << "Coin inserted..." << std::endl;
}

void Game::pressButton()
{
    std::cout << "Button pressed..." << std::endl;
}

void Game::moveStick(sf::Vector2i direction)
{
    std::cout  << "Stick moved: "
                << direction.x << ", " << direction.y << std::endl;
}