#pragma once

#include "AActor.h"

class Manager;

class APlayer : public AActor
{
public:
	APlayer(float width, float height, const char* path, Manager* manager);

	void UpdateTexture(const char* path);
};

