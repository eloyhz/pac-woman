#ifndef PACWOMAN_GAME_HPP
#define PACWOMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include <array>

#include "GameState.hpp"
// class GameState;

class Game
{
public:
    Game();
    ~Game();
    void run();
    void changeGameState(GameState::State gameState);

    sf::Font &getFont();
    sf::Texture &getLogo();
    sf::Texture &getTexture();

private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::State::Count> m_gameStates;

    sf::Font m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
};

#endif