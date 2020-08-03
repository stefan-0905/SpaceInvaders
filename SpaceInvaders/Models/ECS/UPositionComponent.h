#pragma once

#include "ECS.h"


class UPositionComponent : public Component
{
private:
	float x;
	float y;

public:
	UPositionComponent();
	UPositionComponent(float xpos, float ypos);

	/// Getters
	inline float X() const { return x; }
	inline float Y() const { return y; }

	/// Setters
	void SetPosition(float xpos, float ypos);
};