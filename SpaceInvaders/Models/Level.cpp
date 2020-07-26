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

void Level::Generate()
{
	Army->SetEnemyCount(GetEnemyCountBasedOnCurrentLevel());

	Invader** mEnemies = Army->GetEnemies();

	for (int i = 0; i < 30; i++)
		if (mEnemies[i])
		{
			delete mEnemies[i];
			mEnemies[i] = nullptr;
		}

	sf::Vector2f startingPos = sf::Vector2f(WINDOW_SIZE_X / 2 - INVADERS_PER_ROW / 2 * 50, 50.f);
	int Row = 0;

	for (unsigned int i = 0; i < GetEnemyCountBasedOnCurrentLevel(); i++)
	{
		if (i % INVADERS_PER_ROW == 0)
			Row++;

		//TODO Fix placement of stronger enemies from bottom to top
		if (Current == 1)
		{
			mEnemies[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 70.f, startingPos.y + Row * 50.f));
			continue;
		}

		switch (Row)
		{
		case 3:
			mEnemies[i] = new Invader3(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 2:
			mEnemies[i] = new Invader2(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 1:
			mEnemies[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % INVADERS_PER_ROW) * 70.f, startingPos.y + Row * 50.f));
			break;
		default:
			break;
		}
	}
}
