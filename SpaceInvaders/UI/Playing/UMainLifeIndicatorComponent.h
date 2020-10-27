#pragma once

#include "../../Models/ECS/ECS.h"
#include <SFML\Graphics\Text.hpp>

class UHealthComponent;
class UPositionComponent;
class APlayer;

class UMainLifeIndicatorComponent : public Component
{
private:
	UHealthComponent* HealthComponent;
	UPositionComponent* PositionComponent;
	APlayer* Player;

	const int CharacterSize = 20;
	sf::Text HealthText;

public:
	UMainLifeIndicatorComponent(APlayer* mPl);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Draw(sf::RenderWindow& window) override;

};