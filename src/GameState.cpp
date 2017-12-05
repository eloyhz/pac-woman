#include "GameState.hpp"
#include "Game.hpp"

template <typename T>
void centerOrigin(T& drawable)
{
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width/2, bound.height/2);
}

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
{
    m_sprite.setTexture(game->getLogo());
    m_sprite.setPosition(240, 150);

    m_text.setFont(game->getFont());
    m_text.setString("Insert coin!");

//    centerOrigin(m_text);
    m_text.setPosition(240, 150);
    m_displayText = true;
}

void NoCoinState::insertCoin()
{
    getGame()->changeGameState(GameState::GetReady);
}

void NoCoinState::moveStick(sf::Vector2i direction)
{}

void NoCoinState::pressButton()
{}

void NoCoinState::update(sf::Time delta)
{
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    while (timeBuffer >= sf::seconds(0.5)) {
        m_displayText = !m_displayText;
        timeBuffer -= sf::seconds(1);
    }
}

void NoCoinState::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    if (m_displayText)
        window.draw(m_text);
}

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
