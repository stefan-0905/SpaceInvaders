#pragma once

#include "../InvaderArmy.h"
#include "BulletAIController.h"

class PlayerAIController
{
private:
	InvaderArmy* Army;
	BulletAIController m_BulletAIController;
	Side MoveSide;
public:
	PlayerAIController(InvaderArmy* army);
	void Tick(float deltaTime);
	void Fire(float deltaTime);

private:
	sf::Vector2f GetOffset();
};