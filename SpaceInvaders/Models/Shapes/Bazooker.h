#pragma once

#include "Ship.h"

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