#pragma once

#include <SFML/Graphics.hpp>

#include "..\Ship.h"
#include "../../Config.h"

class Invader : public Ship
{
protected:
	sf::Text HPInfo;

public:
	Invader(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		MaxHP = 1;
		HP = static_cast<float>(MaxHP);
		FireDamage = 1;
		FireSpeed = 0.5f;

		HPInfo.setFont(Config::GetFont());
		HPInfo.setCharacterSize(8);
		HPInfo.setFillColor(sf::Color::White);
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));

		Body.setPosition(position);
		HPInfo.setPosition(position.x - width / 2, position.y - height);
		Body.setTexture(&Config::GetInvader1());
	}

	void Draw(sf::RenderWindow& window) override
	{
		window.draw(Body);
		window.draw(HPInfo);
	}

	void Move(float x, float y) override
	{
		HPInfo.move(x, y);
		Body.move(x, y);
	}

	void Move(Side side)
	{
		float moveWidth = 1.f;
		switch (side)
		{
		case Side::Left:
			Move(-moveWidth, 0.f);
			break;
		case Side::Right:
			Move(moveWidth, 0.f);
			break;
		default:
			break;
		}
	}

	void Reset()
	{
		Killed = false;
		HP = static_cast<float>(MaxHP);
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
	}

	void Hurt(float damage)
	{
		HP -= damage;
		if (HP <= 0)
			Killed = true;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
	}

	const sf::Vector2f GetPosition() { return Ship::GetPosition(); }
	bool GetKilled() { return Killed; }
	float GetFireDamage() { return FireDamage; }
};

class Invader1 : public Invader
{
public:
	Invader1(float width, float height, sf::Vector2f position)
		: Invader(width, height, position)
	{
		Type = ShipType::Invader1;
		MaxHP = 1;
		HP = static_cast<float>(MaxHP);
		FireDamage = 1;
		FireSpeed = 0.5f;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));

	}
};

class Invader2 : public Invader
{
public:
	Invader2(float width, float height, sf::Vector2f position)
		: Invader(width, height, position) 
	{
		Type = ShipType::Invader2;
		MaxHP = 2;
		HP = static_cast<float>(MaxHP);
		FireDamage = 1;
		FireSpeed = 0.5f;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));

	}
};

class Invader3 : public Invader
{
public:
	Invader3(float width, float height, sf::Vector2f position)
		: Invader(width, height, position)
	{
		Type = ShipType::Invader3;
		MaxHP = 3;
		HP = static_cast<float>(MaxHP);
		FireDamage = 1;
		FireSpeed = 0.5f;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
	}
};