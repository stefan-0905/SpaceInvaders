#pragma once
#include "Models/Player.h"
#include "Models/Level.h"
#include "Models/InvaderArmy.h"
#include "OverUI.h"
#include "CharacterSelectUI.h"
#include "StartScreenUI.h"
#include "Models/Controllers/PlayerController.h"
#include "Models/Controllers/PlayerAIController.h"

enum class GameState
{
	StartScreen = 0, CharacterSelect, Playing, Over
};

class Game
{
public:
	Player m_Player;
	PlayerController m_PlayerController;
	InvaderArmy Army;
	PlayerAIController m_AIController;
	Level m_Level;
private:
	sf::Font Font;
	StartScreenUI StartScreen;
	OverUI Over;
	CharacterSelectUI CharacterSelect;
	GameState State;
	sf::Text HpText;

public:
	Game(const sf::Vector2f playerSize, const sf::Vector2u windowSize);
	~Game();
	void Tick(float deltaTime);
	void HandleDrawing(sf::RenderWindow& window);
	void HandleStates(sf::Event event, sf::RenderWindow& window);

private:
	void DrawPlaying(sf::RenderWindow& window);
	void DrawStartScreen(sf::RenderWindow& window);
	void DrawCharacherSelect(sf::RenderWindow& window);
	void DrawOver(sf::RenderWindow& window);

	void RestartGame();


};

