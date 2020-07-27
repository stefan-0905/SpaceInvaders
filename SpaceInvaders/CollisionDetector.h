#pragma once

#include "Models/Player.h"
#include "Models/InvaderArmy.h"

class CollisionDetector
{
protected:
	Player* m_Player;
	InvaderArmy* m_Army;
public:
	CollisionDetector(Player* mPlayer, InvaderArmy* mArmy);

	void Tick(float deltaTime);

private:
	void CheckEnemyBulletCollision();
	void CheckPlayerBulletCollision();
};

