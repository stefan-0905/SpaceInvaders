#pragma once

#include <vector>

#include "Invader.h"
#include "Bullet.h"

class InvaderArmy
{
public:
	InvaderArmy(int count, int InvadersPerRow, sf::Texture& texture);
	~InvaderArmy();

	void Draw(sf::RenderWindow& window);
	void Move();
	void Fire();
	void Kill(int position);
	void DestroyBullet(int i);

	std::vector<Invader> GetEnemies() { return Enemies; }
	std::vector<Bullet>* GetBullets() { return &Bullets; }
	int GetCount() const { return Enemies.size(); }

private:
	//Side to which invaders are moving
	Side MoveSide;

	std::vector<Invader> Enemies;
	std::vector<Bullet> Bullets;
	
	//Count of enemies
	unsigned int Count;

	const int InvadersPerRow;

};

