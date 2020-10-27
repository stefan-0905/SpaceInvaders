#pragma once

#include "../SWidget.h"

class SButton : public SWidget
{
public:
	SButton(const wchar_t* title, float xpos, float ypos, bool* resultSelector);
};