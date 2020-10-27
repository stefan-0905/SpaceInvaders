#include "UPositionComponent.h"

#include "USpriteComponent.h"

float Default_Width = 50.f;

USpriteComponent::USpriteComponent()
	: Body(sf::Vector2f(Default_Width, Default_Width))
{
	Body.setFillColor(sf::Color::White);
	SetTexture();
	Body.setOrigin(Body.getGlobalBounds().width / 2, Body.getGlobalBounds().height / 2);
}

USpriteComponent::USpriteComponent(float size_x, float size_y, const char* path)
	: Body(sf::Vector2f(size_x, size_y))
{
	SetTexture(path);
	Body.setOrigin(size_x / 2, size_y / 2);
	Body.setFillColor(sf::Color::White);
}

void USpriteComponent::SetSize(float width, float height)
{
	Body.setSize(sf::Vector2f(width, height));
}

void USpriteComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void USpriteComponent::Tick(float DeltaTime)
{
	if (PositionComponent)
		Body.setPosition(PositionComponent->X(), PositionComponent->Y());
}

void USpriteComponent::Draw(sf::RenderWindow& window)
{
	window.draw(Body);
}

void USpriteComponent::SetTexture(const char* path)
{
	if (path)
	{
		Texture.loadFromFile(path);
		Texture.setSmooth(true);
		Body.setTexture(&Texture);
	}
	else
	{
		sf::Texture testTex;
		if (testTex.create((unsigned int)Body.getGlobalBounds().width, (unsigned int)Body.getGlobalBounds().height))
		{
			Body.setTexture(&testTex);
		}
	}
}
