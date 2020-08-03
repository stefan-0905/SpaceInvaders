#include "UHealthComponent.h"

UHealthComponent::UHealthComponent()
	: MaxHP(0.f)
{
	HP = MaxHP;
}

UHealthComponent::UHealthComponent(float maxHp)
	: MaxHP(maxHp)
{
	HP = MaxHP;
}

void UHealthComponent::DecreaseHealth(float amount)
{
	if (IsKilled()) return; // Don't decrease if hp is 0 already

	if (amount > HP) // If hp should fall below 0, set it to 0
	{
		HP = 0.f;
		return;
	}

	HP -= amount;
}

void UHealthComponent::IncreaseHealth(float amount)
{
	HP += amount;

	if (HP > MaxHP)
	{
		HP = MaxHP;
	}
}
