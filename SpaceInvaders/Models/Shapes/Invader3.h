#pragma once

#include "Invader.h"

class Invader3 : public Invader
{
public:
	Invader3(float width, float height, sf::Vector2f position)
		: Invader(width, height, position)
	{
		Type = ShipType::Invader3;
		MaxHP = 3;
		HP = static_cast<float>(MaxHP);
		Damage = 1;
		FireSpeed = 0.5f;
		HPInfo.setString(std::to_string((int)HP) + "/" + std::to_string(MaxHP));
		Body.setTexture(&Config::GetInvader3());
	}
};