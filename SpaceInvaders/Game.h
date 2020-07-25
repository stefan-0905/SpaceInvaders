#pragma once
#include "Models/Player.h"
#include "Models/Level.h"
#include "Models/InvaderArmy.h"
#include "OverUI.h"
#include "CharacterSelectUI.h"
#include "StartScreenUI.h"

enum class GameState
{
	StartScreen = 0, CharacterSelect, Playing, Over
};

class Game
{
public:
	Player m_Player;
	InvaderArmy Army;
	Level cLevel;
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
	void HandleMoving(float deltaTime);
	void HandleDrawing(sf::RenderWindow& window);
	void HandleStates(sf::Event event, sf::RenderWindow& window);
	void Fire(float& deltaTime);

private:
	void DrawPlaying(sf::RenderWindow& window);
	void DrawStartScreen(sf::RenderWindow& window);
	void DrawCharacherSelect(sf::RenderWindow& window);
	void DrawOver(sf::RenderWindow& window);

	void RestartGame();


};

