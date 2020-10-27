#include "../../Models/ECS/UPositionComponent.h"
#include "../../Models/ECS/USpriteComponent.h"

#include "SImage.h"

SImage::SImage(const char* path, float width, float height, float xpos, float ypos)
{
	AddComponent<UPositionComponent>(xpos, ypos);
	AddComponent<USpriteComponent>(width, height, path);
}
