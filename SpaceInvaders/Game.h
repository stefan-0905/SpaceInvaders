#pragma once
#include "Models/Player.h"
#include "Models/Level.h"
#include "Models/InvaderArmy.h"
#include "OverUI.h"
#include "CharacterSelectUI.h"
#include "StartScreenUI.h"
#include "Models/Controllers/PlayerController.h"
#include "Models/Controllers/PlayerAIController.h"
#include "CollisionDetector.h"
#include "PlayingUI.h"

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

	UIBase* CurrentState;

public:
	Game(const sf::Vector2f playerSize);
	~Game();
	void Tick(float deltaTime);
	void HandleDrawing(sf::RenderWindow& window);
	void HandleStates(sf::Event event, sf::RenderWindow& window);
};

