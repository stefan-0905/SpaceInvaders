#include "Invader.h"

Invader::Invader(sf::Vector2f position)
{
	InvaderTexture = new sf::Texture();
	Left = true;
	InvaderTexture->loadFromFile("res/invader.png");
	//body.setTexture(texture);
	body.setOrigin(sf::Vector2f(25.f, 19.f));
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

	body.setTexture(*InvaderTexture);
}
