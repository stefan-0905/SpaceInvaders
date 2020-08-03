#pragma once

#include "ECS.h"

class UCombatComponent : public Component
{
private:
	float Damage;
	float FiringFrequency;

public:
	UCombatComponent();

	void Fire();
	void SetDamage(float amount);
	void SetFiringFrequency(float amount);
};
