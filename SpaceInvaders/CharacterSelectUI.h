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
	Ship* SelectedShip;

public:
	CharacterSelectUI();
	~CharacterSelectUI();

	inline Ship* GetSelectedShip() { return SelectedShip; }
	inline const sf::Texture* GetTexture() { return SelectedShip->GetTexture(); }
	void Draw(sf::RenderWindow& window);
};

