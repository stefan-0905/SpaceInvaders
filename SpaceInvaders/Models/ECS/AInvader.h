#pragma once

#include "AActor.h"

class AInvader : public AActor
{
public:
	AInvader(float xpos, float ypos, float moveRange);
	virtual void Destroy() override;
};
