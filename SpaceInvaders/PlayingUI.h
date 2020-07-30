#pragma once
#include "SFML/Graphics.hpp"
#include "Models/Player.h"
#include "Models/Controllers/PlayerController.h"
#include "Models/Controllers/PlayerAIController.h"
#include "CollisionDetector.h"
#include "Models/Level.h"
#include "UIBase.h"

class Game;

class PlayingUI : public UIBase
{
public:
	Player m_Player;
	PlayerController m_PlayerController;
	InvaderArmy Army;
	PlayerAIController m_AIController;
	Level m_Level;
	CollisionDetector m_Detector;

	Game* m_Game;

private:
	sf::Text HpText;

public:
	PlayingUI(const sf::Vector2f playerSize, Game* mGame);
	~PlayingUI();

	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	void SetShip(Ship* ship);
	void RestartGame();

private:
	void InitHpText();
};

