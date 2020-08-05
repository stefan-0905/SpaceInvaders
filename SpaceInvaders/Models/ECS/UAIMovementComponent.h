#pragma once

#include "ECS.h"

class UPositionComponent;

class UAIMovementComponent : public Component
{
private:
	UPositionComponent* PositionComponent;
	float MoveRange;
	float CurrentMoveInRange;
	float VelocityX;
	bool LeftSide;
	float StartXPosition;
public:
	UAIMovementComponent(float startX, float moveRange);
	
	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
};