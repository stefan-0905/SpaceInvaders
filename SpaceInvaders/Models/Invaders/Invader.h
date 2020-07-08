#pragma once

#include <SFML/Graphics.hpp>

#include "..\Ship.h"

class Invader1 : public Ship
{
private:
	float MoveSpeed;
public:
	Invader1(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		Killed = false;
		MaxHP = 1;
		FireSpeed = 0.5f;

		Body.setPosition(position);
		Body.setTexture(&Config::GetInvader1());
	}
};

class Invader2 : public Ship
{
private:
	float MoveSpeed;
public:
	Invader2(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		Killed = false;

		MaxHP = 1;
		FireSpeed = 0.5f;

		Body.setPosition(position);
		Body.setTexture(&Config::GetInvader2());
	}
};

class Invader3 : public Ship
{
private:
	float MoveSpeed;
public:
	Invader3(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		Killed = false;

		MaxHP = 1;
		FireSpeed = 0.5f;

		Body.setPosition(position);
		Body.setTexture(&Config::GetInvader3());
	}
};