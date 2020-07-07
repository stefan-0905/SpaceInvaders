#pragma once
#include "Player.h"
#include "InvaderArmy.h"

class Game
{
private:
	Player Player;
	InvaderArmy Army;
public:
	Game(const sf::Vector2f playerSize, const sf::Vector2u windowSize);
	~Game();
	void HandleMoving(float deltaTime);
	void HandleDrawing(sf::RenderWindow& window, sf::Text& text);

};

