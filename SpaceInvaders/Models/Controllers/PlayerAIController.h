#pragma once

#include "../InvaderArmy.h"
#include "BulletAIController.h"

enum class Side
{
	Right = 0, Left
};

class PlayerAIController
{
private:
	InvaderArmy* Army;
	BulletAIController m_BulletAIController;
	Side MoveSide;
	float FireRate;
public:
	PlayerAIController(InvaderArmy* army);

	void Tick(float deltaTime);
	void Fire(float& totalTime);

private:
	sf::Vector2f GetOffset();
};