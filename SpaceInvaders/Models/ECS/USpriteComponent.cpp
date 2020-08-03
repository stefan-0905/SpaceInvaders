#include "UPositionComponent.h"

#include "USpriteComponent.h"


USpriteComponent::USpriteComponent()
	: Body(sf::Vector2f(50.f, 50.f))
{
	Body.setOrigin(25, 25);
}

USpriteComponent::USpriteComponent(float size_x, float size_y, const char* path)
	: Body(sf::Vector2f(size_x, size_y))
{
	Body.setOrigin(size_x / 2, size_y / 2);

	if (path)
	{
		Texture.loadFromFile(path);
		Body.setTexture(&Texture);
	}
}

void USpriteComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();

	if (PositionComponent)
		Body.setPosition(PositionComponent->X(), PositionComponent->Y());
}

void USpriteComponent::Tick(float DeltaTime)
{
	if(PositionComponent)
		Body.setPosition(PositionComponent->X(), PositionComponent->Y());
}

void USpriteComponent::Draw(sf::RenderWindow& window)
{
	window.draw(Body);
}
