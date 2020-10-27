#pragma once

#include "../Widget.h"

class APlayer;

class HPWidget : public Widget
{
public:
	HPWidget(float xpos, float ypos, APlayer* mPl);
};