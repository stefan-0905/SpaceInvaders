#include "SelectState.h"
#include "USelectedStateComponent.h"

USelectedStateComponent::USelectedStateComponent()
{
}

void USelectedStateComponent::SetState(SelectState state)
{
	State = state;
}
