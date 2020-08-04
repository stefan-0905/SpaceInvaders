#include "UPositionComponent.h"

#include "../../Constants.h"

#include "UProjectileMovementComponent.h"

UProjectileMovementComponent::UProjectileMovementComponent(bool playerProjectile)
{
	PlayerProjectile = playerProjectile;
	VelocityY = 200.f;
}

void UProjectileMovementComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void UProjectileMovementComponent::Tick(float DeltaTime)
{
	if (!PositionComponent) return;
	float xpos = PositionComponent->X();
	float ypos = PositionComponent->Y();

	if (PlayerProjectile)
	{
		/// Move Up
		PositionComponent->Move(0.f, -VelocityY * DeltaTime);
	}
	else
	{
		/// Move down
		PositionComponent->Move(0.f, VelocityY * DeltaTime);
	}

	/// Remove if past screen depending if its gooing up or down
	if (PlayerProjectile &&  ypos < -50.f)
	{
		GetOwner()->Destroy();
	}
	if (!PlayerProjectile && ypos > WINDOW_SIZE_Y + 50.f)
	{
		GetOwner()->Destroy();
	}
}
