#include <iostream>

#include "InvaderArmy.h"
#include <memory>

InvaderArmy::InvaderArmy(int level, int invadersPerRow)
	: Level(level), InvadersPerRow(invadersPerRow)
{
	Bullets.reserve(InvadersPerRow);
	InitiateArmy();
}


InvaderArmy::~InvaderArmy()
{
	for (unsigned int i = 0; i < GetCount(); i++)
	{
		delete Enemies[i];
		Enemies[i] = nullptr;
	}
	delete[]Enemies;
}

void InvaderArmy::InitiateArmy()
{
	Enemies = new Invader * [GetCount()];
	sf::Vector2f startingPos = sf::Vector2f(1024.f / 2 - InvadersPerRow / 2 * 50, 50.f);
	int Row = 0;


	// Example of unique pointers
	/*std::unique_ptr<std::unique_ptr<Killable*>[]> Enemies;
	Enemies = std::make_unique<std::unique_ptr<Killable*>[]>(3);
	Enemies[0] = std::make_unique<Killable*>(new Invader1(...));
	Enemies[1] = std::make_unique<Killable*>(new Invader1(...));
	Enemies[2] = std::make_unique<Killable*>(new Invader1(...));
	for (int i = 0; i < 3; i++)
	{
		(*(Enemies.get())[i])->Print();
	}*/

	for (unsigned int i = 0; i < GetCount(); i++)
	{
		if (i % InvadersPerRow == 0)
			Row++;

		//TODO Fix placement of stronger enemies from bottom to top
		if (Level == 1)
		{
			Enemies[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			continue;
		}

		switch (Row)
		{
		case 3:
			Enemies[i] = new Invader3(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 2:
			Enemies[i] = new Invader2(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 1:
			Enemies[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		default:
			break;
		}
	}
}

void InvaderArmy::Draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < GetCount(); i++)
	{
		if (!Enemies[i]->GetKilled())
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
	for (unsigned int i = 0; i < GetCount(); i++)
	{
		Enemies[i]->Move(MoveSide);
	}

	/// Check if enemies are nearing the edge of the screen 
	if (Enemies[0]->GetPosition().x < 100)
		MoveSide = Side::Right;

	if (Enemies[GetCount() - 1]->GetPosition().x > 924)
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
	int column = rand() % InvadersPerRow;

	/// Get the last row
	int row = (int)ceil(GetCount() / InvadersPerRow) - 1 ;

	/// Determine the row of the invader that's not killed in the random column we got
	/// Row is getting substracted if invader is killed in that row
	/// Finally, finding the position of alive invader or not finding him and not firing the bullet
	do {
		if (!Enemies[row * InvadersPerRow + column]->GetKilled())
		{
			sf::Vector2f invaderPosition = Enemies[row * InvadersPerRow + column]->GetPosition();
			invaderPosition.y += 50;
			Bullets.emplace_back(Bullet(invaderPosition, Enemies[row * InvadersPerRow + column]->GetFireDamage()));
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
	for (unsigned int i = 0; i < GetCount(); i++)
	{
		if (i == position) {
			Enemies[i]->Hurt(damage);
			if (Enemies[i]->GetKilled())
				KillCount++;
		}
	}

	unsigned int EnemyCountPerLevel = 0;

	/// Base on KillCount SwitchLevels
	if (KillCount >= GetCount())
	{
		/// Remove old enemies
		for (unsigned int i = 0; i < GetCount(); i++)
			delete Enemies[i];
		delete[]Enemies;

		Level++;
		//TODO Finish Game

		KillCount = 0;
		

		InitiateArmy();
	}
}

void InvaderArmy::DestroyBullet(int i)
{
	Bullets.erase(Bullets.begin() + i);
}

void InvaderArmy::Reset()
{
	for (unsigned int i = 0; i < GetCount(); i++)
	{
		Enemies[i]->Reset();
	}

	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		DestroyBullet(i);
	}
}
