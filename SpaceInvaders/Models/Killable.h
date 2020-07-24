#pragma once

#include "SFML/Graphics.hpp"

enum class Side {
	Left = 0, Right
};


class Killable
{
public:
	virtual bool GetKilled() = 0;
	virtual float GetFireDamage() = 0;
	virtual const sf::Vector2f GetPosition() = 0;
	virtual void Reset() = 0;
	virtual void Hurt(float damage) = 0;
	virtual void Move(Side side) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual ~Killable() {};
};