#pragma once

#include "ECS.h"

class AActor : public Entity
{
public:
	AActor();
	AActor(float width, float height, const char* path = nullptr);

};

