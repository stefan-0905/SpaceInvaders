#pragma once
#include <SFML\Graphics.hpp>

#include "Config.h"

class Ship
{
protected:
	sf::RectangleShape Body;
	unsigned int MaxHP;

public:
	float FireSpeed;
	Ship(float width, float height)
		:Body(sf::Vector2f(width, height))
	{
		Body.setTexture(&Config::GetSlingerTexture());
		printf(std::to_string(GetSize().height).c_str());
		printf(std::to_string(GetSize().width).c_str());
		Body.setOrigin(width / 2, height / 2);
	};

	void SetPosition(float x, float y) 
	{
		Body.setPosition(x, y);
	};

	void Draw(sf::RenderWindow& window)
	{
		window.draw(Body);
	}

	void Move(float x, float y)
	{
		Body.move(x, y);
	}

	void SetSize(sf::FloatRect newSize)
	{
		Body.setSize(sf::Vector2f(newSize.width, newSize.height));
	}

	inline sf::Vector2f GetPosition() const { return Body.getPosition(); }
	inline sf::RectangleShape& GetShape() { return Body; }
	inline unsigned int GetMaxHP() const { return MaxHP; }
	inline sf::FloatRect GetSize() const { return Body.getGlobalBounds(); }
};

class Slinger : public Ship
{
public:
	Slinger(float width, float height)
		: Ship(width, height)
	{
		MaxHP = 5;
		FireSpeed = 0.5f;

		Body.setTexture(&Config::GetSlingerTexture());
	}
};

class Bazooker : public Ship
{
public:
	Bazooker(float width, float height)
		: Ship(width, height)
	{
		MaxHP = 10;
		FireSpeed = 1.f;

		Body.setTexture(&Config::GetBazookerTexture());
	}
};