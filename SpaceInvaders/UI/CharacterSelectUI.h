#pragma once
#include <SFML\Graphics\Text.hpp>
#include "../Constants.h"
#include "UIBase.h"

class Ship;
class RenderWindow;
class Texture;

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
	const sf::Texture* GetTexture();

private: 
	void InitTitle();
	void InitShips();
	void InitSelector();

};

