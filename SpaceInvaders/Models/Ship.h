#pragma once
#include <SFML\Graphics.hpp>

#include "../Config.h"

enum class Side {
	Left = 0, Right
};

class Killable
{
public:
	unsigned int HP;
	bool Killed = false;
	virtual void Reset() = 0;
	virtual void Hurt() = 0;
	virtual void Move(Side side) = 0;
	virtual sf::Vector2f GetPosition() const = 0;
	virtual sf::RectangleShape& GetShape() = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual ~Killable() {};
};


class Ship : public Killable
{
protected:
	sf::RectangleShape Body;
	unsigned int MaxHP;

public:
	float FireSpeed;
	Ship(float width, float height)
		:Body(sf::Vector2f(width, height))
	{
		Killed = false;
		//Body.setTexture(&Config::GetSlingerTexture());
		Body.setOrigin(width / 2, height / 2);
	};

	virtual void Reset() override
	{
		Killed = false;
		HP = MaxHP;
	}

	virtual void Hurt() override
	{
		--HP;
		if (HP == 0)
			Killed = true;
	}

	void SetPosition(float x, float y) 
	{
		Body.setPosition(x, y);
	};

	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(Body);
	}

	virtual void Move(float x, float y)
	{
		Body.move(x, y);
	}

	void SetSize(sf::FloatRect newSize)
	{
		Body.setSize(sf::Vector2f(newSize.width, newSize.height));
	}

	virtual void Move(Side side) override
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

	virtual inline sf::Vector2f GetPosition() const override { return Body.getPosition(); }
	virtual inline sf::RectangleShape& GetShape() override { return Body; }
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
		HP = MaxHP;
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
		HP = MaxHP;
		FireSpeed = 1.f;

		Body.setTexture(&Config::GetBazookerTexture());
	}
};