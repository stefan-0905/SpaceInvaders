#include "BulletAIController.h"

#include "../../Constants.h"

BulletAIController::BulletAIController(std::vector<Bullet>* bullets)
	: Bullets(bullets)
{

}

BulletAIController::~BulletAIController()
{
}

void BulletAIController::Tick(float deltaTime)
{
	for (unsigned int i = 0; i < Bullets->size(); i++)
	{
		Bullets->at(i).Move();

		/// Removing player bullets when they past screen
		if (Bullets->at(i).GetDirection() == Bullet::Direction::Up && Bullets->at(i).GetPosition().y <= 0)
		{
			Bullets->erase(Bullets->begin() + i);
			continue;
		}

		/// Remove enemy bullets when they past screen
		if (Bullets->at(i).GetDirection() == Bullet::Direction::Down && Bullets->at(i).GetPosition().y > WINDOW_SIZE_Y)
		{
			Bullets->erase(Bullets->begin() + i);
			continue;
		}
	}
}