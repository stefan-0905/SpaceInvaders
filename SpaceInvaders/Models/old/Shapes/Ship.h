#pragma once

#include "../../../Config.h"
#include "Shape.h"

class RenderWindow;

class Ship : public Shape
{
protected:
	// Maximum HP
	unsigned int MaxHP;
	// Current ammount of HP
	float HP;
	// Is killed
	bool Killed;
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

	inline unsigned int GetMaxHP() const { return MaxHP; }
	inline float GetFireSpeed() const { return FireSpeed; }
	inline float GetDamage() const { return Damage; }
};