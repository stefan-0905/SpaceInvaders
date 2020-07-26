#include "BulletAIController.h"

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

		/// Remove if bullet misses everything and exits screen
		if (Bullets->at(i).GetPosition().y <= 0)
		{
			Bullets->erase(Bullets->begin() + i);
			continue;
		}
	}
}