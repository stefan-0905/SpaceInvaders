#include "UPositionComponent.h"


UPositionComponent::UPositionComponent()
{
	SetPosition(0.f, 0.f);
}

UPositionComponent::UPositionComponent(float xpos, float ypos)
{
	SetPosition(xpos, ypos);
}

void UPositionComponent::SetPosition(float xpos, float ypos)
{
	x = xpos;
	y = ypos;
}
