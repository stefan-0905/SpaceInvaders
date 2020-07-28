#include "PlayerController.h"

PlayerController::PlayerController(Player* p)
	: m_Player(p), m_BulletAIController(p->GetBullets())
{
    FiringCounter = 0.f;
}

void PlayerController::Tick(float deltaTime)
{
    FiringCounter += deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_Player->GetShip()->Move(-5.f, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_Player->GetShip()->Move(5.f, 0.0f);
    }
    
    if (m_Player->GetShip()->GetPosition().x < 50)
        m_Player->SetPosition(50, m_Player->GetShip()->GetPosition().y);

    if (m_Player->GetShip()->GetPosition().x > 974)
        m_Player->SetPosition(974, m_Player->GetShip()->GetPosition().y);

    m_BulletAIController.Tick(deltaTime);
}

void PlayerController::Fire()
{
    if (FiringCounter >= m_Player->GetFireRate())
    {
        m_Player->Fire();
        FiringCounter = 0;
    }
}