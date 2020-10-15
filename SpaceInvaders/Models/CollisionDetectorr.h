#pragma once

class Player;
class InvaderArmy;

class CollisionDetectorr
{
protected:
	Player* m_Player;
	InvaderArmy* m_Army;
public:
	CollisionDetectorr(Player* mPlayer, InvaderArmy* mArmy);

	void Tick(float deltaTime);

private:
	void CheckEnemyBulletCollision();
	void CheckPlayerBulletCollision();
};

