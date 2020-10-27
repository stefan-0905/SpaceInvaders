#include "../../Models/ECS/UPositionComponent.h"
#include "USelectController.h"
#include "UTextComponent.h"
#include "SButton.h"

SButton::SButton(const wchar_t* title, float xpos, float ypos, bool selected, bool* resultSelector)
{
	AddComponent<UPositionComponent>(xpos, ypos);
	AddComponent<UTextComponent>(title);
	
	AddComponent<USelectController>(resultSelector);
}
