#include "SFML/Graphics/RenderWindow.hpp"

#include "Ship.h"

Ship::Ship(float width, float height)
	: Shape(width, height)
{
	Killed = false;
}

void Ship::ResetKilled()
{
	Killed = false;
	HP = static_cast<float>(MaxHP);
}

void Ship::Move(float x, float y)
{
	Shape::Move(x, y);
}

void Ship::Draw(sf::RenderWindow& window)
{
	Shape::Draw(window);
}
