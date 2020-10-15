#include "Manager.h"
#include "AProjectile.h"
#include "UPositionComponent.h"

#include "UCombatComponent.h"
#include "USpriteComponent.h"

UCombatComponent::UCombatComponent(Manager* manager)
	: m_Manager(manager)
{
	Damage = 1.f;
	FiringFrequency = 0.2f;
}

void UCombatComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void UCombatComponent::Tick(float DeltaTime)
{
	OverallTime += DeltaTime;
}

void UCombatComponent::Fire()
{
	if (OverallTime > FiringFrequency)
	{
		if (!PositionComponent) return;
		auto x = PositionComponent->X();
		auto y = PositionComponent->Y();

		// Spawn projectile above player
		float PlayerHeight = GetOwner()->GetComponent<USpriteComponent>().GetSize().y;

		m_Manager->AddActor<AProjectile>(PositionComponent->X(), PositionComponent->Y() - PlayerHeight);
		OverallTime = 0.f;
	}
}

void UCombatComponent::SetDamage(float amount)
{
	Damage = amount;
}

void UCombatComponent::SetFiringFrequency(float amount)
{
	FiringFrequency = amount;
}
