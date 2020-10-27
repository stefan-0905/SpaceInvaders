#pragma once

#include "../SWidget.h"

class APlayer;

class HPWidget : public SWidget
{
public:
	HPWidget(float xpos, float ypos, APlayer* mPl);
};