#include "Invader.h"

Invader::Invader(float width, float height, sf::Vector2f position)
	: Ship(width, height)
{
	MaxHP = 1;
	HP = static_cast<float>(MaxHP);
	Damage = 1;
	FireSpeed = 0.5f;

	HPInfo.setFont(Config::GetFont());
	HPInfo.setCharacterSize(8);
	HPInfo.setFillColor(sf::Color::White);
	HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));

	Body.setPosition(position);
	HPInfo.setPosition(position.x - width / 2, position.y - height);
	Body.setTexture(&Config::GetInvader1());
}

void Invader::Draw(sf::RenderWindow& window)
{
	window.draw(Body);
	window.draw(HPInfo);
}

void Invader::Move(float x, float y)
{
	HPInfo.move(x, y);
	Body.move(x, y);
}

void Invader::Reset()
{
	Killed = false;
	HP = static_cast<float>(MaxHP);
	HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
}

void Invader::Hurt(float damage)
{
	HP -= damage;
	if (HP <= 0)
		Killed = true;
	HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
}
