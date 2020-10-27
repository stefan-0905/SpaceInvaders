#include "../../Models/ECS/UPositionComponent.h"
#include "../../Models/ECS/APlayer.h"

#include "UMainLifeIndicatorComponent.h"

#include "HPWidget.h"

HPWidget::HPWidget(float xpos, float ypos, APlayer* mPl)
{
	AddComponent<UPositionComponent>(xpos, ypos);
	AddComponent<UMainLifeIndicatorComponent>(mPl);
}
