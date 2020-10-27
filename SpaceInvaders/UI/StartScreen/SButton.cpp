#include "../../Models/ECS/UPositionComponent.h"
#include "USelectControllerComponent.h"
#include "UTextComponent.h"
#include "SButton.h"

SButton::SButton(const wchar_t* title, float xpos, float ypos, bool* resultSelector)
{
	AddComponent<UPositionComponent>(xpos, ypos);
	AddComponent<UTextComponent>(title);
	AddComponent<USelectControllerComponent>(resultSelector);
}
