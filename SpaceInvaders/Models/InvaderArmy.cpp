#include <iostream>

#include "InvaderArmy.h"

InvaderArmy::InvaderArmy(int level, int invadersPerRow)
	: Level(level), InvadersPerRow(invadersPerRow)
{
	Bullets.reserve(InvadersPerRow);

	InitiateArmy();
}


InvaderArmy::~InvaderArmy()
{
	for (unsigned int i = 0; i < GetCount(); i++)
		delete Enemies1[i];
	delete[]Enemies1;
}

void InvaderArmy::InitiateArmy()
{
	printf("Initiation");
	Enemies1 = new Killable*[GetCount()];

	sf::Vector2f startingPos = sf::Vector2f(1024.f / 2 - InvadersPerRow / 2 * 50, 50.f);
	int Row = 0;

	for (unsigned int i = 0; i < GetCount(); i++)
	{
		if (i % InvadersPerRow == 0)
			Row++;

		//TODO Fix placement of stronger enemies from bottom to top

		if (Level == 1)
		{
			Enemies1[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			continue;
		}

		switch (Row)
		{
		case 3:
			Enemies1[i] = new Invader3(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 2:
			Enemies1[i] = new Invader2(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 1:
			Enemies1[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
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
		if (!Enemies1[i]->Killed)
			Enemies1[i]->Draw(window);
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
		Enemies1[i]->Move(MoveSide);
	}

	/// Check if enemies are nearing the edge of the screen 
	if (Enemies1[0]->GetPosition().x < 100)
		MoveSide = Side::Right;

	if (Enemies1[GetCount() - 1]->GetPosition().x > 924)
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
		if (!Enemies1[row * InvadersPerRow + column]->Killed)
		{
			sf::Vector2f invaderPosition = Enemies1[row * InvadersPerRow + column]->GetPosition();
			invaderPosition.y += 50;
			Bullets.emplace_back(Bullet(invaderPosition, Enemies1[row * InvadersPerRow + column]->FireDamage));
			totalTime -= 1;
			break;
		}
		else 
		{
			--row;
		}
	} while (row >= 0);

}

void InvaderArmy::Injure(int position, int damage)
{
	/// Set invader on specified position as killed
	for (unsigned int i = 0; i < GetCount(); i++)
	{
		if (i == position) {
			Enemies1[i]->Hurt(damage);
			if (Enemies1[i]->Killed)
				KillCount++;
		}
	}

	unsigned int EnemyCountPerLevel = 0;

	/// Base on KillCount SwitchLevels
	if (KillCount >= GetCount())
	{
		/// Remove old enemies
		for (unsigned int i = 0; i < GetCount(); i++)
			delete Enemies1[i];
		delete[]Enemies1;

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
		Enemies1[i]->Reset();
	}

	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		DestroyBullet(i);
	}
}
