#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

#include "Ship.h"
#include "../../../Config.h"

class Invader : public Ship
{
protected:
	sf::Text HPInfo;

public:
	Invader(float width, float height, sf::Vector2f position);
	~Invader();

	virtual void Draw(sf::RenderWindow& window) override;

	virtual void Move(float x, float y) override;
	// Reset an invader, changing it's values to default ones
	void Reset();
	// Hurt an invader by the amount of damage specified and update hpinfo text
	void Hurt(float damage);

	const sf::Vector2f GetPosition() { return Ship::GetPosition(); }
	bool GetKilled() { return Killed; }
};