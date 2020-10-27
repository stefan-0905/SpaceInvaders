#pragma once

#include "../../Models/ECS/ECS.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Color.hpp"

class UPositionComponent;

class UTextComponent : public Component
{
private:
	UPositionComponent* PositionComponent;

	sf::Text TextBox;

	const wchar_t* Title;
	const int CharacterSize = 18;

public:
	UTextComponent(const wchar_t* title);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Draw(sf::RenderWindow& window) override;

	const wchar_t* GetTitle() const { return Title; }
	void UpdateText(const wchar_t* text);

	void SetColor(sf::Color color);
};