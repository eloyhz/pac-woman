#ifndef PACWOMAN_GAME_HPP
#define PACWOMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include <array>
class Game
{
public:
    Game();
    ~Game();
    void run();
    void changeGameState(GameState::State gameState);
private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::State::Count> m_gameStates;
};

#endif