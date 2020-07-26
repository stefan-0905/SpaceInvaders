#pragma once
#include <SFML\Graphics.hpp>

#include "../Config.h"
#include "Shape.h"
#include "Killable.h"

enum class ShipType
{
	Undefined = 0, Slinger, Bazooker, Invader1, Invader2, Invader3
};

class Ship : public Shape
{
protected:
	//sf::RectangleShape Body;
	unsigned int MaxHP;
	float HP;
	bool Killed;
	ShipType Type;
	float FireDamage;
	float FireSpeed;
public:
	Ship(float width, float height);

	void ResetKilled();

	virtual void Move(float x, float y) override;
	virtual void Draw(sf::RenderWindow& window);

	inline ShipType GetType() const { return Type; }
	inline unsigned int GetMaxHP() const { return MaxHP; }
	inline float GetFireSpeed() const { return FireSpeed; }
	inline float GetDamage() const { return FireDamage; }
};



class Slinger : public Ship
{
public:
	Slinger(float width, float height)
		: Ship(width, height)
	{
		Type = ShipType::Slinger;
		MaxHP = 5;
		HP = static_cast<float>(MaxHP);
		FireDamage = 1;
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
		Type = ShipType::Bazooker;
		MaxHP = 10;
		HP = static_cast<float>(MaxHP);
		FireDamage = 3;
		FireSpeed = 0.1f;

		Body.setTexture(&Config::GetBazookerTexture());
	}
};