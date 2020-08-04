#include "InvaderArmy.h"
#include "Invaders.hpp"

#include "Level.h"
#include "../Constants.h"


Level::Level(InvaderArmy* army)
{
	Army = army;
	StartNewGame();
}

Level::~Level()
{}

unsigned int Level::GetEnemyCountBasedOnCurrentLevel() const
{
	switch (Current)
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

void Level::StartNewGame()
{
	Current = 1;

	for (unsigned int i = 0; i < Army->GetBullets()->size(); i++)
	{
		Army->DestroyBullet(i);
	}

	Generate();
}

void Level::Next()
{
	++Current;
	if(Current <= MaxLevel) Generate();
}

bool Level::Completed() const
{
	return Army->EnemiesDestroyed();
}

void Level::Generate()
{
	// Set adequate enemy count based on level
	Army->SetEnemyCount(GetEnemyCountBasedOnCurrentLevel());

	Invader** mEnemies = Army->GetEnemies();

	/// Delete previous enemies
	for (int i = 0; i < 30; i++)
		if (mEnemies[i])
		{
			delete mEnemies[i];
			mEnemies[i] = nullptr;
		}
	// If the width of an invader is 40px and we occupy 60 for each, we need to make 10px margin. That's why we are adding 10px to x.
	sf::Vector2f startingPos = sf::Vector2f(WINDOW_SIZE_X / 2 - INVADERS_PER_ROW / 2 * 60 + 10, 50.f);
	int Row = 0;

	for (unsigned int i = 0; i < GetEnemyCountBasedOnCurrentLevel(); i++)
	{
		if (i % INVADERS_PER_ROW == 0)
			Row++;

		if (Current == 1)
		{
			mEnemies[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 60.f, startingPos.y + Row * 50.f));
			continue;
		}

		switch (Row)
		{
		case 3:
			mEnemies[i] = new Invader3(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 60.f, startingPos.y + Row * 50.f));
			break;
		case 2:
			mEnemies[i] = new Invader2(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 60.f, startingPos.y + Row * 50.f));
			break;
		case 1:
			mEnemies[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 60.f, startingPos.y + Row * 50.f));
			break;
		default:
			break;
		}
	}
}
