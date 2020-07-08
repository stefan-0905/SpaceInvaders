#include <iostream>

#include "InvaderArmy.h"

InvaderArmy::InvaderArmy(int count, int invadersPerRow)
	: Count(count), InvadersPerRow(invadersPerRow)
{
	//Enemies.reserve(Count);
	Bullets.reserve(InvadersPerRow);

	//Enemies1.reserve(Count);
	Enemies1 = new Enemy*[Count];

	sf::Vector2f startingPos = sf::Vector2f(1024.f / 2 - InvadersPerRow / 2 * 50, 50.f);

	int Row = 0;
	for (unsigned int i = 0; i < Count; i++)
	{
		if (i % InvadersPerRow == 0)
		{
			Row++;

			printf("%s \n", "Inscrementing");
		}
		//Enemies.emplace_back(Invader(sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f)));
		switch (Row)
		{
		case 1:
			Enemies1[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 2:
			Enemies1[i] = new Invader2(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		case 3:
			Enemies1[i] = new Invader3(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
			break;
		default:
			break;
		}
		//Enemies1[i] = new Invader1(40.f, 30.f, sf::Vector2f(startingPos.x + (i % InvadersPerRow) * 70.f, startingPos.y + Row * 50.f));
	}
}

InvaderArmy::~InvaderArmy()
{
	
}

void InvaderArmy::Draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < Count; i++)
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
	for (unsigned int i = 0; i < Count; i++)
	{
		Enemies1[i]->Move(MoveSide);
	}

	/// Check if enemies are nearing the edge of the screen 
	if (Enemies1[0]->GetPosition().x < 100)
		MoveSide = Side::Right;

	if (Enemies1[Count - 1]->GetPosition().x > 924)
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
	int row = (int)ceil(Count / InvadersPerRow) - 1 ;

	/// Determine the row of the invader that's not killed in the random column we got
	/// Row is getting substracted if invader is killed in that row
	/// Finally, finding the position of alive invader or not finding him and not firing the bullet
	do {
		if (!Enemies1[row * InvadersPerRow + column]->Killed)
		{
			sf::Vector2f invaderPosition = Enemies1[row * InvadersPerRow + column]->GetPosition();
			invaderPosition.y += 50;
			Bullets.emplace_back(Bullet(invaderPosition));
			totalTime -= 1;
			break;
		}
		else 
		{
			--row;
		}
	} while (row >= 0);

}

void InvaderArmy::Kill(int position)
{
	/// Set invader on specified position as killed
	for (unsigned int i = 0; i < Count; i++)
	{
		if (i == position) {
			Enemies1[i]->Killed = true;
		}
	}
}

void InvaderArmy::DestroyBullet(int i)
{
	Bullets.erase(Bullets.begin() + i);
}

void InvaderArmy::Reset()
{
	for (unsigned int i = 0; i < Count; i++)
	{
		Enemies1[i]->Killed = false;
	}

	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		Bullets.erase(Bullets.begin() + i);
	}
}
