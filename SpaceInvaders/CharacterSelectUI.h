#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Models\Ship.h"

class CharacterSelectUI
{
private:
	std::vector<Ship> Ships;

	//TOD Check if this index is needed
	unsigned int ShipIndex;
	sf::RectangleShape Selector;

	sf::Text Title;

public:
	Ship* SelectedShip;
	CharacterSelectUI();
	~CharacterSelectUI();

	void Draw(sf::RenderWindow& window);
};

