#include "Ship.h"

Ship::Ship(float width, float height)
	: Shape(width, height)
{
	Type = ShipType::Undefined;
	Killed = false;
}

void Ship::ResetKilled()
{
	Killed = false;
	HP = static_cast<float>(MaxHP);
}
//
//void Ship::Hurt(int damage)
//{
//	HP -= damage;
//	if (HP <= 0)
//		Killed = true;
//}
//
//void Ship::Move(Side side)
//{
//	float moveWidth = 1.f;
//	switch (side)
//	{
//	case Side::Left:
//		Shape::Move(-moveWidth, 0.f);
//		break;
//	case Side::Right:
//		Shape::Move(moveWidth, 0.f);
//		break;
//	default:
//		break;
//	}
//}

void Ship::Move(float x, float y)
{
	Shape::Move(x, y);
}

void Ship::Draw(sf::RenderWindow& window)
{
	Shape::Draw(window);
}
