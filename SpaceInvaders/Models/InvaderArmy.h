#pragma once

#include <vector>

#include "Invaders\Invader.h"
#include "Bullet.h"
#include "Ship.h"

class InvaderArmy
{
public:
	InvaderArmy(int count, int InvadersPerRow);
	~InvaderArmy();

	void Draw(sf::RenderWindow& window);
	void Move();
	void Fire(float deltaTime);
	void Kill(int position);
	void DestroyBullet(int i);
	void Reset();

	Enemy** GetEnemies() { return Enemies1; }
	std::vector<Bullet>* GetBullets() { return &Bullets; }
	int GetCount() const { return Count; }

private:
	//Side to which invaders are moving
	Side MoveSide;

	std::vector<Bullet> Bullets;
	
	Enemy** Enemies1;

	//Count of enemies
	unsigned int Count;

	const int InvadersPerRow;

};

