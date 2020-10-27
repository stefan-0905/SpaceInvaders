#pragma once

#include "../../Models/ECS/ECS.h"

class UPositionComponent;
class USelectedStateComponent;

class USelectorMovementComponent : public Component
{
private:
	UPositionComponent* PositionComponent;
	USelectedStateComponent* SelectedStateComponent;

public:
	USelectorMovementComponent();

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
};
