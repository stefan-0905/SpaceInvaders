#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Models\Ship.h"
#include "Constants.h"


class CharacterSelectUI
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

	inline Ship* GetSelectedShip() { return SelectedShip; }
	inline const sf::Texture* GetTexture() { return SelectedShip->GetTexture(); }
	void Draw(sf::RenderWindow& window);
};

