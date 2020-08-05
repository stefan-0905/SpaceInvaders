#include "UPositionComponent.h"
#include "USpriteComponent.h"
#include "../../Constants.h"

#include "AActor.h"

AActor::AActor()
	: Entity()
{
	AddComponent<UPositionComponent>();
	AddComponent<USpriteComponent>();
}

AActor::AActor(float width, float height, const char* path)
	: Entity()
{
	AddComponent<UPositionComponent>(WINDOW_SIZE_X / 2, (float)WINDOW_SIZE_Y - 50);
	AddComponent<USpriteComponent>(width, height, path);
}

AActor::AActor(float width, float height, const char* path, float xpos, float ypos)
	: Entity()
{
	AddComponent<UPositionComponent>(xpos, ypos);
	AddComponent<USpriteComponent>(width, height, path);
}