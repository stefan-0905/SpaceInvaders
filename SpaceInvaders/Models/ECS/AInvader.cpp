
#include "UAIMovementComponent.h"

#include "AInvader.h"
#include "UHealthIndicatorComponent.h"
#include "UHealthComponent.h"

AInvader::AInvader(float xpos, float ypos, float moveRange)
	: AActor(30.f, 30.f, "res/invader1.png", xpos, ypos)
{
	AddComponent<UAIMovementComponent>(xpos, moveRange);
	AddComponent<UHealthComponent>(1.f);
	AddComponent<UHealthIndicatorComponent>();
}
