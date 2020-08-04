#include "UPositionComponent.h"
#include "USpriteComponent.h"

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
	AddComponent<UPositionComponent>(width, height);
	AddComponent<USpriteComponent>(width, height, path);
}
