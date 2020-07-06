#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position)
{
	sf::Texture texture;
	if (texture.create(2, 5))
	{
		body.setTexture(texture);
		body.setOrigin(sf::Vector2f(0.25f, 10.f));
		body.setPosition(position);
	}

}

Bullet::~Bullet()
{
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Bullet::Move(int direction)
{
	if (direction) {
		body.move(0.f, -3.f);
	} 
	else {
		body.move(0.f, 3.f);
	}
}

bool Bullet::Intersects(sf::Sprite& shape)
{
	return body.getGlobalBounds().intersects(shape.getGlobalBounds());
}
