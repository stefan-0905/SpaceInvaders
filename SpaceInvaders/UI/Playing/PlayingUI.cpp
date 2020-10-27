#include "SFML/Graphics/RenderWindow.hpp"
#include "../../Game.h"
#include "../../Config.h"

#include "../../Models/ECS/UHealthComponent.h"
#include "../../Spawner.h"

#include "HPWidget.h"

#include "PlayingUI.h"

PlayingUI::PlayingUI(const sf::Vector2f playerSize, Game* mGame)
	: mPl(manager.AddActor<APlayer>(50.f, 50.f, "res/Slinger.png", &manager))
{
    m_Game = mGame;
    manager.AddActor<HPWidget>(WINDOW_SIZE_X - 100.f - 50.f, 10.f, &mPl);

    Spawner::Spawn(20, &manager);
}

PlayingUI::~PlayingUI()
{
}

void PlayingUI::Tick(float deltaTime)
{
    manager.Refresh();
    manager.Tick(deltaTime);
    /*if (m_Level.Completed())
    {
        m_Level.Next();
    }*/

    // Move Invading Army Left - Right
    //m_AIController.Tick(deltaTime);

    // Move Player And his assets - bullets
    //m_PlayerController.Tick(deltaTime);

    //m_Detector.Tick(deltaTime);

    UHealthComponent PlayerHealth = mPl.GetComponent<UHealthComponent>();

    HpText.setString("Lives:" + std::to_string((int)PlayerHealth.GetHealth()) + "/" + std::to_string((int)PlayerHealth.GetMaxHealth()));

    if (PlayerHealth.IsKilled())
    {
        manager.Refresh();
        m_Game->FinishGame(false);
    }
    else {
       /* if (m_Level.GetCurrentLevel() > Level::MaxLevel)
        {
            m_Game->FinishGame(true);
        }*/
    }
}

void PlayingUI::Draw(sf::RenderWindow& window)
{
    manager.Draw(window);
    window.draw(HpText);
}

void PlayingUI::SetShip(Ship* ship)
{
    //m_Player.SetShip(ship);
}

void PlayingUI::RestartGame()
{
    //m_Level.StartNewGame();
    //m_Player.ResetShip();
    //m_Player.CleanBullets();
}
