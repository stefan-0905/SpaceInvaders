#pragma once

#include "ECS.h"

class Manager;
class UPositionComponent;

class UCombatComponent : public Component
{
private:
	Manager* m_Manager;
	UPositionComponent* PositionComponent;
	float Damage;
	float FiringFrequency;

	float OverallTime;

public:
	UCombatComponent(Manager* manager);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;

	void Fire();
	void SetDamage(float amount);
	void SetFiringFrequency(float amount);
};
