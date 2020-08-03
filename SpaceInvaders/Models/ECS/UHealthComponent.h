#pragma once

#include "ECS.h"

class UHealthComponent : public Component
{
private:
	const float MaxHP;
	float HP;

public:
	UHealthComponent();
	UHealthComponent(float maxHp);

	inline float GetMaxHealth() const { return MaxHP; }
	inline float GetHealth() const { return HP; }
	inline float IsKilled() const { return HP == 0.f; }

	void DecreaseHealth(float amount = 1.f);
	void IncreaseHealth(float amount = 1.f);
};
