
#include "../../Models/ECS/UPositionComponent.h"
#include "../../Models/ECS/USpriteComponent.h"

#include "../../Constants.h"

#include "SBanner.h"

SBanner::SBanner()
{
	AddComponent<UPositionComponent>(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
	AddComponent<USpriteComponent>(200, 100, "res/title.jpg");
}
