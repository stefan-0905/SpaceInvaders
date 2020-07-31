#pragma once

#include "Invader.h"

class Invader1 : public Invader
{
public:
	Invader1(float width, float height, sf::Vector2f position)
		: Invader(width, height, position)
	{
		Type = ShipType::Invader1;
		MaxHP = 1;
		HP = static_cast<float>(MaxHP);
		Damage = 1;
		FireSpeed = 0.5f;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
		Body.setTexture(&Config::GetInvader1());
	}
};