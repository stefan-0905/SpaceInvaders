#include "Invader.h"

Invader::Invader(sf::Vector2f position)
	: body(sf::Vector2f(40.f, 30.f))
{
	InvaderTexture = new sf::Texture();
	Left = true;
	InvaderTexture->loadFromFile("res/invader.png");

	body.setOrigin(sf::Vector2f(20.f, 15.f));
	body.setPosition(position);
	SetTexture();
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

void Invader::SetTexture()
{
	//if(body.getTexture() == nullptr)
		
	/*InvaderTexture.loadFromFile("res/invader.png");*/

	body.setTexture(InvaderTexture);
}
