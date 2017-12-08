#include <iostream>
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
{
    m_text.setFont(game->getFont());
    m_text.setString("Press Start when you're ready...");
    m_text.setCharacterSize(14);

//    centerOrigin(m_text);
    m_text.setPosition(240, 240);
}

void GetReadyState::insertCoin()
{}

void GetReadyState::moveStick(sf::Vector2i direction)
{
}

void GetReadyState::pressButton()
{
    getGame()->changeGameState(GameState::Playing);
}

void GetReadyState::update(sf::Time delta)
{}

void GetReadyState::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}

//////////////////////// PlayingState ////////////////////////
PlayingState::PlayingState(Game* game)
: GameState(game)
, m_pacWoman(game->getTexture())
, m_ghost(game->getTexture())
{
    m_pacWoman.move(100, 100);
    m_ghost.move(200, 200);
}

void PlayingState::insertCoin()
{
    m_pacWoman.die();
}

void PlayingState::moveStick(sf::Vector2i direction)
{
    if (direction.x == -1)
        getGame()->changeGameState(GameState::Lost);
    else if (direction.y == 1)
        getGame()->changeGameState(GameState::Won);
}

void PlayingState::pressButton()
{
    m_ghost.setWeak(sf::seconds(3));
}

void PlayingState::update(sf::Time delta)
{
    m_pacWoman.update(delta);
    m_ghost.update(delta);
}

void PlayingState::draw(sf::RenderWindow& window)
{
    window.draw(m_pacWoman);
    window.draw(m_ghost);
}

//////////////////////// WonState ////////////////////////
WonState::WonState(Game* game)
:GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("You won!");
    m_text.setCharacterSize(42);

    // centerOrigin(m_text);
    m_text.setPosition(240, 120);
}

void WonState::insertCoin()
{}

void WonState::moveStick(sf::Vector2i direction)
{}

void WonState::pressButton()
{}

void WonState::update(sf::Time delta)
{
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;

    if (timeBuffer.asSeconds() >= 5) {
        getGame()->changeGameState(GameState::GetReady);
    }
}

void WonState::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
}

//////////////////////// LostState ////////////////////////
LostState::LostState(Game* game)
:GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("You lost!");
    m_text.setCharacterSize(42);

    // centerOrigin(m_text);
    m_text.setPosition(240, 120);

    m_countDownText.setFont(game->getFont());
    m_countDownText.setCharacterSize(12);

    // centerOrigin(m_countDownText);
    m_countDownText.setPosition(240, 240);

    m_countDown = sf::seconds(0);
}

void LostState::insertCoin()
{}

void LostState::moveStick(sf::Vector2i direction)
{}

void LostState::pressButton()
{}

void LostState::update(sf::Time delta)
{
    m_countDown += delta;
    if (m_countDown.asSeconds() >= 10) {
        getGame()->changeGameState(GameState::NoCoin);
    }
    m_countDownText.setString("Insert coin to continue... " +
        std::to_string(10 - static_cast<int>(m_countDown.asSeconds()))
    );
}

void LostState::draw(sf::RenderWindow& window)
{
    window.draw(m_text);
    window.draw(m_countDownText);
}

