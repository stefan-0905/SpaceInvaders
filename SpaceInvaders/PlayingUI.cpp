#include "PlayingUI.h"

#include "Game.h"

PlayingUI::PlayingUI(const sf::Vector2f playerSize, Game* mGame)
	: m_Player(sf::Vector2f(playerSize.x, playerSize.y)), m_PlayerController(&m_Player), Army(30), m_AIController(&Army), m_Level(&Army), m_Detector(&m_Player, &Army)
{
    m_Game = mGame;
    m_Player.SetPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y - m_Player.GetSize().y);

    InitHpText();
}

PlayingUI::~PlayingUI()
{
}

void PlayingUI::Tick(float deltaTime)
{
    if (m_Level.Completed())
    {
        m_Level.Next();
    }

    // Move Invading Army Left - Right
    m_AIController.Tick(deltaTime);

    // Move Player And his assets - bullets
    m_PlayerController.Tick(deltaTime);

    m_Detector.Tick(deltaTime);

    HpText.setString("Lives:" + std::to_string((int)m_Player.GetHP()) + "/" + std::to_string(m_Player.GetMaxHP()));

    if (!m_Player.Alive())
    {
        m_Game->FinishGame(false);
    }
    else {
        if (m_Level.GetCurrentLevel() > Level::MaxLevel)
        {
            m_Game->FinishGame(true);
        }
    }
}

void PlayingUI::Draw(sf::RenderWindow& window)
{
    m_Player.Draw(window);
    Army.Draw(window);
    window.draw(HpText);
}

void PlayingUI::SetShip(Ship* ship)
{
    m_Player.SetShip(ship);
}

void PlayingUI::RestartGame()
{
    m_Level.StartNewGame();
    m_Player.ResetShip();
    m_Player.CleanBullets();
}

void PlayingUI::InitHpText()
{
    HpText.setFont(Config::GetFont());
    HpText.setCharacterSize(20);
    HpText.setFillColor(sf::Color::White);
    HpText.setPosition(WINDOW_SIZE_X - 100.f - 50.f, 10.f);
}
