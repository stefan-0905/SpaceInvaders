#pragma once

#include "../../Models/ECS/ECS.h"
#include "SFML/Window/Keyboard.hpp"

class UTextComponent;

class USelectController : public Component
{
private:
	UTextComponent* TextComponent;
	sf::Keyboard::Key StartKey;
	sf::Keyboard::Key QuitKey;

	bool* ResultSelector;

public:
	USelectController(bool* resultSelector);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
};