#pragma once
#include "../UIBase.h"

#include "../../Models/ECS/ECS.h"
#include "../../Models/ECS/Manager.h"

class RenderWindow;

class SSelector;
enum class SelectState;

class CharacterSelectUI : public UIBase
{
private:
	Manager manager;

	SSelector* Selector;

public:
	CharacterSelectUI();
	~CharacterSelectUI();

	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	const SelectState& GetSelectedShip() const;
};

