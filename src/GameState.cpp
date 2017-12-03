#include "GameState.hpp"

GameState::GameState(Game* game)
:m_game(game)
{}

GameState::~GameState() 
{}

Game* GameState::getGame() const
{
    return m_game;
}

//////////////////////// NoCoinState ////////////////////////

NoCoinState::NoCoinState(Game* game)
:GameState(game)
{}

void NoCoinState::insertCoin()
{}

void NoCoinState::moveStick(sf::Vector2i direction)
{}

void NoCoinState::pressButton()
{}

void NoCoinState::update(sf::Time delta)
{}

void NoCoinState::draw(sf::RenderWindow& window)
{}

//////////////////////// GetReadyState ////////////////////////

GetReadyState::GetReadyState(Game* game)
:GameState(game)
{}

void GetReadyState::insertCoin()
{}

void GetReadyState::moveStick(sf::Vector2i direction)
{}

void GetReadyState::pressButton()
{}

void GetReadyState::update(sf::Time delta)
{}

void GetReadyState::draw(sf::RenderWindow& window)
{}

//////////////////////// PlayingState ////////////////////////
PlayingState::PlayingState(Game* game)
:GameState(game)
{}

void PlayingState::insertCoin()
{}

void PlayingState::moveStick(sf::Vector2i direction)
{}

void PlayingState::pressButton()
{}

void PlayingState::update(sf::Time delta)
{}

void PlayingState::draw(sf::RenderWindow& window)
{}

//////////////////////// WonState ////////////////////////
WonState::WonState(Game* game)
:GameState(game)
{}

void WonState::insertCoin()
{}

void WonState::moveStick(sf::Vector2i direction)
{}

void WonState::pressButton()
{}

void WonState::update(sf::Time delta)
{}

void WonState::draw(sf::RenderWindow& window)
{}

//////////////////////// LostState ////////////////////////
LostState::LostState(Game* game)
:GameState(game)
{}

void LostState::insertCoin()
{}

void LostState::moveStick(sf::Vector2i direction)
{}

void LostState::pressButton()
{}

void LostState::update(sf::Time delta)
{}

void LostState::draw(sf::RenderWindow& window)
{}
