#pragma once

#include "../../Models/ECS/ECS.h"
#include "SelectState.h"

class USelectedStateComponent : public Component
{
private:
	SelectState State;

public:
	USelectedStateComponent();

	const SelectState& GetState() const { return State; }
	void SetState(SelectState state);

};