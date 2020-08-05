#include "UPositionComponent.h"
#include "UAIMovementComponent.h"
#include <iostream>

UAIMovementComponent::UAIMovementComponent(float startX, float moveRange)
{
	MoveRange = moveRange;
	CurrentMoveInRange = 0;
	VelocityX = 100.f;
	LeftSide = false;
	StartXPosition = startX;
}

void UAIMovementComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void UAIMovementComponent::Tick(float DeltaTime)
{
	if (MoveRange <= 0) return;
	float move = VelocityX * DeltaTime;
	if (LeftSide)
	{
		// If there is space to move, move, else set at on the edge
		if (CurrentMoveInRange > move)
		{
			PositionComponent->Move(-move, 0.f);
			CurrentMoveInRange -= move;
		}
		else
		{
			PositionComponent->SetPosition(StartXPosition, PositionComponent->Y());
			LeftSide = false;
		}
	}
	else
	{
		if (MoveRange - CurrentMoveInRange > move)
		{
			PositionComponent->Move(move, 0.f);
			CurrentMoveInRange += move;
		}
		else
		{
			PositionComponent->SetPosition(StartXPosition + MoveRange, PositionComponent->Y());
			LeftSide = true;
		}
	}
}
