#pragma once

#include "UI.hpp"

class Manager;

enum class GameState
{
	StartScreen = 0, CharacterSelect, Playing, Over
};

class Game
{
public:
	PlayingUI Playing;
private:
	StartScreenUI StartScreen;
	CharacterSelectUI CharacterSelect;
	OverUI Over;
	GameState State;

	UIBase* CurrentUIState;

public:
	Game(Manager& manager, const sf::Vector2f playerSize);
	~Game();

	void Tick(float deltaTime);
	void HandleDrawing(sf::RenderWindow& window);
	void HandleStates(sf::Event event, sf::RenderWindow& window);

	void FinishGame(bool success);
};

