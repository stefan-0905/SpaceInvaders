#include "UPositionComponent.h"


#include "UColliderComponent.h"
#include "CollisionDetector.h"

UColliderComponent::UColliderComponent(float width, float height)
{
	Collider.width = width;
	Collider.height = height;
	Collider.top = 0.f;
	Collider.left = 0.f;
}

void UColliderComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void UColliderComponent::Tick(float DeltaTime)
{
	Collider.left = PositionComponent->X();
	Collider.top = PositionComponent->Y();
}