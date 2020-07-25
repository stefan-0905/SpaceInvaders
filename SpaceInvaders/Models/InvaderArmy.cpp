#include <iostream>

#include "InvaderArmy.h"
#include "../Constants.h"
#include <memory>

InvaderArmy::InvaderArmy(unsigned int maxEnemies)
	: MaxEnemies(maxEnemies)
{
	EnemyCount = 0;
	Bullets.reserve(INVADERS_PER_ROW);
	Enemies = new Invader * [MaxEnemies];
	for (unsigned int i = 0; i < MaxEnemies; i++)
	{
		Enemies[i] = nullptr;
	}
}

InvaderArmy::~InvaderArmy()
{
	for (unsigned int i = 0; i < MaxEnemies; i++)
	{
		delete Enemies[i];
		Enemies[i] = nullptr;
	}
	delete[]Enemies;
}

void InvaderArmy::Draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < EnemyCount; i++)
	{
		if (Enemies[i] && !Enemies[i]->GetKilled())
			Enemies[i]->Draw(window);
	}

	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		Bullets[i].Draw(window);
	}
}

void InvaderArmy::Move()
{
	/// Move all enemies
	for (unsigned int i = 0; i < EnemyCount; i++)
	{
		if(Enemies[i])
			Enemies[i]->Move(MoveSide);
	}

	/// Check if enemies are nearing the edge of the screen 
	if (Enemies[0]->GetPosition().x < 100)
		MoveSide = Side::Right;

	if (Enemies[EnemyCount - 1]->GetPosition().x > 924)
		MoveSide = Side::Left;

	/// Move bullets and delete all that moved out of the screen
	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		Bullets[i].Move(0);

		if (Bullets[i].GetPosition().y > 512)
		{
			Bullets.erase(Bullets.begin() + i);
			continue;
		}
	}
}

void InvaderArmy::Fire(float deltaTime)
{
	static float totalTime = 0.f;
	totalTime += deltaTime;

	if (totalTime < 1.f) return;

	/// Get random column for the bullet
	int column = rand() % INVADERS_PER_ROW;

	/// Get the last row
	int row = (int)ceil(EnemyCount / INVADERS_PER_ROW) - 1 ;

	/// Determine the row of the invader that's not killed in the random column we got
	/// Row is getting substracted if invader is killed in that row
	/// Finally, finding the position of alive invader or not finding him and not firing the bullet
	do {
		auto enemy = Enemies[row * INVADERS_PER_ROW + column];
		if (enemy && !enemy->GetKilled())
		{
			sf::Vector2f invaderPosition = enemy->GetPosition();
			invaderPosition.y += 50;
			Bullets.emplace_back(Bullet(invaderPosition, enemy->GetFireDamage()));
			totalTime -= 1.f;
			break;
		}
		else 
		{
			--row;
		}
	} while (row >= 0);
}

void InvaderArmy::Injure(int position, float damage)
{
	/// Set invader on specified position as killed
	for (unsigned int i = 0; i < EnemyCount; i++)
	{
		if (i == position && Enemies[i]) {
			Enemies[i]->Hurt(damage);
			if (Enemies[i]->GetKilled())
				KillCount++;
		}
	}
}

void InvaderArmy::DestroyBullet(int i)
{
	Bullets.erase(Bullets.begin() + i);
}

void InvaderArmy::SetEnemyCount(unsigned int count)
{
	EnemyCount = count;
	KillCount = 0;
}