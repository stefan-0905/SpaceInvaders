#pragma once

#include "UI.hpp"

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
	Game(const sf::Vector2f playerSize);
	~Game();

	void Tick(float deltaTime);
	void HandleDrawing(sf::RenderWindow& window);
	void HandleStates(sf::Event event, sf::RenderWindow& window);

	void FinishGame(bool success);
};

