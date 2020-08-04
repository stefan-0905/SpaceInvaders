#pragma once

#include "ECS.h"

class UPositionComponent;

class UPlayerMovementComponent : public Component
{
protected:
	UPositionComponent* PositionComponent;
	// Player Acceleration
	float Acceleration;

	// Velocity for x coordinate
	float VelocityX;

	// Maximum velocity player can reach
	float MaxVelocity;

public:
	UPlayerMovementComponent();
	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
};