#pragma once

#include "ECS.h"
#include <SFML\Graphics\Text.hpp>

class UHealthComponent;
class UPositionComponent;
class USpriteComponent;

class UHealthIndicatorComponent : public Component
{
private:
	UHealthComponent* HealthComponent;
	UPositionComponent* PositionComponent;
	USpriteComponent* SpriteComponent;

	const int CharacterSize = 8;
	sf::Text HealthText;

public:
	UHealthIndicatorComponent();

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Draw(sf::RenderWindow& window) override;

};
