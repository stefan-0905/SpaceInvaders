#include "../../Models/ECS/UPositionComponent.h"
#include "../StartScreen/UTextComponent.h"

#include "SStaticText.h"

SStaticText::SStaticText(const wchar_t* title, float xpos, float ypos, sf::Color color)
{
	AddComponent<UPositionComponent>(xpos, ypos);
	textComponent = &AddComponent<UTextComponent>(title);
	textComponent->SetColor(color);
}
