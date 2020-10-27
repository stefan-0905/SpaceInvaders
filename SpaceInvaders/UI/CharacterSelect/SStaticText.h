#pragma once


#include "../SWidget.h"

class UTextComponent;

class SStaticText : public SWidget
{
private:
	UTextComponent* textComponent;
public:
	SStaticText(const wchar_t* title, float xpos, float ypos, sf::Color color = sf::Color::White);
};