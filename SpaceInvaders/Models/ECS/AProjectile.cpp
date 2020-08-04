#include "UPositionComponent.h"
#include "UProjectileMovementComponent.h"
#include "AProjectile.h"

AProjectile::AProjectile(float xpos, float ypos)
	// TODO Adjust dimensions and texture
	: AActor(2.f, 5.f)
{
	GetComponent<UPositionComponent>().SetPosition(xpos, ypos);
	AddComponent<UProjectileMovementComponent>();
}
