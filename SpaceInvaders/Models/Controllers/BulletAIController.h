#pragma once

#include "../Bullet.h"

class BulletAIController
{
protected:
	std::vector<Bullet>* Bullets;
public:
	BulletAIController(std::vector<Bullet>* bullets);
	~BulletAIController();

	void Tick(float deltaTime);
};