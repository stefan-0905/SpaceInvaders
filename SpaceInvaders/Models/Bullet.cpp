#include "Bullet.h"
#include "../Config.h"

Bullet::Bullet(sf::Vector2f position, float damage)
	: Shape(2, 5)
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

void Bullet::Move(int direction)
{
	if (direction) {
		Shape::Move(0.f, -3.f);
	} 
	else {
		Shape::Move(0.f, 3.f);
	}
}

bool Bullet::Intersects(Shape* shape)
{
	return Shape::Colliding(shape);
}
