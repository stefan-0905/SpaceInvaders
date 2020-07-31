#pragma once

#include "Ship.h"

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