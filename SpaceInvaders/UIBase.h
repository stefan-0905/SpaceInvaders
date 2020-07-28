#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

class UIBase
{
public:
	virtual void Tick(float deltaTime) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};