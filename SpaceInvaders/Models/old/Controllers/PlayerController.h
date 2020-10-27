#pragma once

#include "BulletAIController.h"

class Player;

class PlayerController
{
protected:
	Player* m_Player;
	BulletAIController m_BulletAIController;

	float FiringCounter;
public:
	PlayerController(Player* p);

	void Tick(float deltaTime);
	void Fire();
};