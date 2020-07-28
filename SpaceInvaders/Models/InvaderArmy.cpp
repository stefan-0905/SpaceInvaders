#include <iostream>

#include "InvaderArmy.h"
#include "../Constants.h"

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
		//TODO Maybe check killed property in Draw function
		if (Enemies[i] && !Enemies[i]->GetKilled())
			Enemies[i]->Draw(window);
	}

	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		Bullets[i].Draw(window);
	}
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

void InvaderArmy::DestroyBullet(int position)
{
	Bullets.erase(Bullets.begin() + position);
}

void InvaderArmy::SetEnemyCount(unsigned int count)
{
	EnemyCount = count;
	KillCount = 0;
}