#pragma once

#include "ECS.h"

class UPositionComponent;

class UProjectileMovementComponent : public Component
{
private:
	bool PlayerProjectile;
	float VelocityY;
	UPositionComponent* PositionComponent;

public:
	UProjectileMovementComponent(bool playerProjectile = true);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
};