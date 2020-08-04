#include "UPositionComponent.h"

#include "USpriteComponent.h"

float Default_Width = 50.f;

USpriteComponent::USpriteComponent()
	: Body(sf::Vector2f(Default_Width, Default_Width))
{
	Body.setOrigin(Default_Width / 2, Default_Width / 2);
	sf::Texture testTex;
	if (testTex.create(2, 5))
	{
		Body.setTexture(&testTex);
	}
	Body.setFillColor(sf::Color::White);
}

USpriteComponent::USpriteComponent(float size_x, float size_y, const char* path)
	: Body(sf::Vector2f(size_x, size_y))
{
	Body.setOrigin(size_x / 2, size_y / 2);
	Body.setFillColor(sf::Color::White);
	if (path)
	{
		Texture.loadFromFile(path);
		Body.setTexture(&Texture);
	}
	else
	{
		sf::Texture testTex;
		if (testTex.create(size_x, size_y))
		{
			Body.setTexture(&testTex);
		}
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

void USpriteComponent::SetTexture(const char* path)
{
	Texture.loadFromFile(path);
	Body.setTexture(&Texture);
}
