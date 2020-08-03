#include "UCombatComponent.h"

UCombatComponent::UCombatComponent()
{
	Damage = 1.f;
	FiringFrequency = 1.f;
}

void UCombatComponent::Fire()
{

}

void UCombatComponent::SetDamage(float amount)
{
	Damage = amount;
}

void UCombatComponent::SetFiringFrequency(float amount)
{
	FiringFrequency = amount;
}
