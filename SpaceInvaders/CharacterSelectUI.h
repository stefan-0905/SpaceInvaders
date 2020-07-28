#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Models\Ship.h"
#include "Constants.h"
#include "UIBase.h"

class CharacterSelectUI : public UIBase
{
private:
	Ship* Ships[CS_NUMBER_OF_SHIPS];

	// Enables dynamic track of selected ship's index
	unsigned int ShipIndex;
	Ship* SelectedShip;

	Shape Selector;
	sf::Text Title;

public:
	CharacterSelectUI();
	~CharacterSelectUI();

	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	inline Ship* GetSelectedShip() { return SelectedShip; }
	inline const sf::Texture* GetTexture() { return SelectedShip->GetTexture(); }

private: 
	void InitTitle();
	void InitShips();
	void InitSelector();

};

