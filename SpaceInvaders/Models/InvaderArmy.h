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
	Killable** Enemies1;
	int InvadersPerRow;
	unsigned int KillCount = 0;

public:
	int Level;
	InvaderArmy(int level, int InvadersPerRow);
	~InvaderArmy();

	void Draw(sf::RenderWindow& window);
	void Move();
	void Fire(float deltaTime);
	void Injure(int position, int damage);
	void DestroyBullet(int i);
	void Reset();

	Killable** GetEnemies() { return Enemies1; }
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

	InvaderArmy& operator=(const InvaderArmy& other);

private:
	void InitiateArmy();
};

