#pragma once
#include <SFML\Graphics.hpp>

#include "../Config.h"
#include "Shape.h"

enum class ShipType
{
	Undefined = 0, Slinger, Bazooker, Invader1, Invader2, Invader3
};

class Ship : public Shape
{
protected:
	// Maximum HP
	unsigned int MaxHP;
	// Current ammount of HP
	float HP;
	// Is killed
	bool Killed;
	// Ship type
	ShipType Type;
	// Damage
	float Damage;
	// Firing speed
	float FireSpeed;
public:
	Ship(float width, float height);

	// Set to not killed
	void ResetKilled();

	virtual void Move(float x, float y) override;
	virtual void Draw(sf::RenderWindow& window);

	inline ShipType GetType() const { return Type; }
	inline unsigned int GetMaxHP() const { return MaxHP; }
	inline float GetFireSpeed() const { return FireSpeed; }
	inline float GetDamage() const { return Damage; }
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
		Damage = 1;
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
		Damage = 2;
		FireSpeed = 1.f;

		Body.setTexture(&Config::GetBazookerTexture());
	}
};