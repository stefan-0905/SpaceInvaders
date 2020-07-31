#pragma once

#include "Invader.h"

class Invader2 : public Invader
{
public:
	Invader2(float width, float height, sf::Vector2f position)
		: Invader(width, height, position)
	{
		Type = ShipType::Invader2;
		MaxHP = 2;
		HP = static_cast<float>(MaxHP);
		Damage = 1;
		FireSpeed = 0.5f;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
		Body.setTexture(&Config::GetInvader2());
	}
};