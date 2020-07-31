#pragma once

#include <vector>

#include "Shapes/Bullet.h"

class Invader;
class RenderWindow;

class InvaderArmy
{
private:
	// Bullets fired by enemies
	std::vector<Bullet> Bullets;
	// Enemies on a level
	Invader** Enemies;
	// Maximum number of enemies that can spawn on a level
	unsigned int MaxEnemies;
	// Number of enemies spawned
	unsigned int EnemyCount;
	// Number of enemies killed on a level
	unsigned int KillCount = 0;

public:
	InvaderArmy(unsigned int enemyCount);
	~InvaderArmy();

	void Draw(sf::RenderWindow& window);
	// Inflict damage to enemy at specific position. If it gets killed set it as so
	void Injure(int position, float damage);
	// Remove bullet at position
	void DestroyBullet(int position);
	// Set number of enemies that should be spawn. By setting it, KillCount is also reseted
	void SetEnemyCount(unsigned int count);
	// Get enemies
	Invader** GetEnemies() { return Enemies; }
	// Get bullets
	std::vector<Bullet>* GetBullets() { return &Bullets; }
	// Get enemy count
	inline unsigned int GetEnemyCount() { return EnemyCount; };
	// See if all enemies are killed on a level
	inline bool EnemiesDestroyed() { return EnemyCount == KillCount; }
};

