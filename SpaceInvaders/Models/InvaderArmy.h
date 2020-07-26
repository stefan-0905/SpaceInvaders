#pragma once

#include <vector>

#include "Invaders\Invader.h"
#include "Bullet.h"

class InvaderArmy
{
private:
	std::vector<Bullet> Bullets;
	Invader** Enemies;
	unsigned int MaxEnemies;
	unsigned int EnemyCount;
	unsigned int KillCount = 0;

public:
	InvaderArmy(unsigned int enemyCount);
	~InvaderArmy();

	void Draw(sf::RenderWindow& window);
	void Injure(int position, float damage);
	void DestroyBullet(int i);

	void SetEnemyCount(unsigned int count);

	Invader** GetEnemies() { return Enemies; }
	std::vector<Bullet>* GetBullets() { return &Bullets; }

	inline unsigned int GetEnemyCount() { return EnemyCount; };
	inline bool EnemiesDestroyed() { return EnemyCount == KillCount; }
};

