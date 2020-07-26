#pragma once

#include "SFML/Window/Event.hpp"
#include "../Game.h"

class EventHandler
{
private:
	Game* m_Game;
	sf::RenderWindow* m_Window;
public:
	EventHandler(Game* mGame, sf::RenderWindow* window);

	void Handle(sf::Event ev, float& deltaTimeWhenUserTriesToFire);
};