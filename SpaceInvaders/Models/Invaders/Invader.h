#pragma once

#include <SFML/Graphics.hpp>

#include "..\Ship.h"
#include "../../Config.h"

class Invader1 : public Ship
{
private:
	float MoveSpeed;
	sf::Text HPInfo;
public:
	Invader1(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		MaxHP = 1;
		HP = MaxHP;
		FireSpeed = 0.5f;

		HPInfo.setFont(Config::GetFont());
		HPInfo.setCharacterSize(8);
		HPInfo.setFillColor(sf::Color::White);
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));

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

	void Move(Side side) override
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

	void Reset() override
	{
		Killed = false;
		HP = MaxHP;
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));
	}

	void Hurt() override
	{
		--HP;
		if (HP == 0)
			Killed = true;
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));
	}
};

class Invader2 : public Ship
{
private:
	float MoveSpeed;
	sf::Text HPInfo;

public:
	Invader2(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		MaxHP = 2;
		HP = MaxHP;
		FireSpeed = 0.5f;

		HPInfo.setFont(Config::GetFont());
		HPInfo.setCharacterSize(8);
		HPInfo.setFillColor(sf::Color::White);
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));

		Body.setPosition(position);
		HPInfo.setPosition(position.x - width / 2, position.y - height);
		Body.setTexture(&Config::GetInvader2());
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

	void Move(Side side) override
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
	void Hurt() override
	{
		--HP;
		if (HP == 0)
			Killed = true;
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));
	}
};

class Invader3 : public Ship
{
private:
	float MoveSpeed;
	sf::Text HPInfo;

public:
	Invader3(float width, float height, sf::Vector2f position)
		: Ship(width, height)
	{
		MaxHP = 3;
		HP = MaxHP;
		FireSpeed = 0.5f;

		HPInfo.setFont(Config::GetFont());
		HPInfo.setCharacterSize(8);
		HPInfo.setFillColor(sf::Color::White);
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));

		Body.setPosition(position);
		HPInfo.setPosition(position.x - width / 2, position.y - height);
		Body.setTexture(&Config::GetInvader3());
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

	void Move(Side side) override
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

	void Hurt() override
	{
		--HP;
		if (HP == 0)
			Killed = true;
		HPInfo.setString(std::to_string(HP) + "/" + std::to_string(MaxHP));
	}
};