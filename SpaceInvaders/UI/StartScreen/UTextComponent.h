#pragma once

#include "../../Models/ECS/ECS.h"
#include "../../Models/ECS/UPositionComponent.h"

#include "SFML/Graphics/Text.hpp"

class UTextComponent : public Component
{
private:
	UPositionComponent* PositionComponent;

	sf::Text TextBox;

	const wchar_t* Title;
	const int CharacterSize = 18;

	bool Selected;
public:
	UTextComponent(const wchar_t* title, bool selected);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void IsSelected(bool selected);
	const wchar_t* GetTitle() const { return Title; }
};