#include "../../Models/ECS/UPositionComponent.h"
#include "../../Models/ECS/USpriteComponent.h"
#include "USelectorMovementComponent.h"
#include "USelectedStateComponent.h"

#include "../../Constants.h"

#include "SSelector.h"

SSelector::SSelector()
{
	AddComponent<UPositionComponent>(WINDOW_SIZE_X / 2 - 50, WINDOW_SIZE_Y / 2 + 100);
	AddComponent<USpriteComponent>(50, 5);
	AddComponent<USelectedStateComponent>();
	AddComponent<USelectorMovementComponent>();
}

const SelectState& SSelector::GetState() const
{
	return GetComponent<USelectedStateComponent>().GetState();
}
