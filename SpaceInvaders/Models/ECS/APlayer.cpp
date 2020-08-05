#include "UHealthComponent.h"
#include "UHealthIndicatorComponent.h"
#include "UPlayerMovementComponent.h"
#include "UCombatComponent.h"
#include "Manager.h"

#include "APlayer.h"

APlayer::APlayer(float width, float height, const char* path, Manager* manager)
	: AActor(width, height, path)
{
	AddComponent<UHealthComponent>(3.f);
	//AddComponent<UHealthIndicatorComponent>();
	AddComponent<UCombatComponent>(manager);
	AddComponent<UPlayerMovementComponent>();
}