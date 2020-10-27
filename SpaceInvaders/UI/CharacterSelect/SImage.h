#pragma once

#include "../SWidget.h"

class SImage : public SWidget
{
public:
	SImage(const char* path, float width, float height, float xpos, float ypos);
};