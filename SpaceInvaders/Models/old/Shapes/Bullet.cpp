
#include "Bullet.h"
#include "../../../Config.h"

Bullet::Bullet(sf::Vector2f position, float damage, Direction moveDirection)
	: Shape(2, 5), MoveDirection(moveDirection)
{
	sf::Texture testTex;
	if (testTex.create(2, 5))
	{
		Shape::SetTexture(&testTex);
	}
	SetPosition(position.x, position.y);
	Body.setFillColor(sf::Color::White);
	Damage = damage;
}

Bullet::~Bullet()
{
}

void Bullet::Draw(sf::RenderWindow& window)
{
	Shape::Draw(window);
}

void Bullet::Move()
{
	if (MoveDirection == Direction::Up) {
		Shape::Move(0.f, -3.f);
	} 
	
	if(MoveDirection == Direction::Down) 
	{
		Shape::Move(0.f, 3.f);
	}
}