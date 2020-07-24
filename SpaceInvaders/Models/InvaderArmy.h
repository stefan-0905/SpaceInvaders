#pragma once

#include <vector>

#include "Invaders\Invader.h"
#include "Bullet.h"
#include "Ship.h"

class InvaderArmy
{
private:
	//Side to which invaders are moving
	Side MoveSide;
	std::vector<Bullet> Bullets;
	Invader** Enemies;
	int InvadersPerRow;
	unsigned int KillCount = 0;

public:
	int Level;
	InvaderArmy(int level, int InvadersPerRow);
	~InvaderArmy();

	void Draw(sf::RenderWindow& window);
	void Move();
	void Fire(float deltaTime);
	void Reset();
	void Injure(int position, float damage);
	void DestroyBullet(int i);

	Invader** GetEnemies() { return Enemies; }
	std::vector<Bullet>* GetBullets() { return &Bullets; }
	unsigned int GetCount() const 
	{
		switch (Level)
		{
		case 1:
			return 20;
			break;
		case 2:
			return 20;
			break;
		case 3:
			return 30;
			break;
		default:
			return 0;
			break;
		}
	}

private:
	void InitiateArmy();

};

