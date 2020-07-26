#include "PlayerController.h"

PlayerController::PlayerController(Player* p)
	: mPlayer(p)
{
}

void PlayerController::Move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        mPlayer->GetShip()->Move(-5.f, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mPlayer->GetShip()->Move(5.f, 0.0f);
    }

    if (mPlayer->GetShip()->GetPosition().x < 50)
        mPlayer->SetPosition(50, mPlayer->GetShip()->GetPosition().y);

    if (mPlayer->GetShip()->GetPosition().x > 974)
        mPlayer->SetPosition(974, mPlayer->GetShip()->GetPosition().y);

}

void PlayerController::Fire(float& deltaTime)
{
    if (deltaTime >= mPlayer->GetFireRate())
    {
        mPlayer->Fire();
        deltaTime = 0;
    }
}
