#include "Invader.h"

Invader::Invader(sf::Vector2f position, sf::Texture& texture)
{
	Left = true;
	body.setTexture(texture);
	body.setOrigin(sf::Vector2f(25.f, 19.f));
	body.setPosition(position);
}

void Invader::Draw(sf::RenderWindow& window)
{
	if(!Killed)
		window.draw(body);
}

void Invader::Move(Side side)
{
	float moveWidth = 1.f;
	switch (side)
	{
	case Side::Left:
		body.move(-moveWidth, 0.f);
		break;
	case Side::Right:
		body.move(moveWidth, 0.f);
		break;
	default:
		break;
	}
}
