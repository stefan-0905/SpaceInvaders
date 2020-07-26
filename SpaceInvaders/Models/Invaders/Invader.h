#pragma once

#include <SFML/Graphics.hpp>

#include "..\Ship.h"
#include "../../Config.h"

class Invader : public Ship
{
protected:
	sf::Text HPInfo;

public:
	Invader(float width, float height, sf::Vector2f position);

	virtual void Draw(sf::RenderWindow& window) override;

	virtual void Move(float x, float y) override;

	void Reset();

	void Hurt(float damage);

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
		Body.setTexture(&Config::GetInvader1());
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
		Body.setTexture(&Config::GetInvader2());
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
		Body.setTexture(&Config::GetInvader3());
	}
};