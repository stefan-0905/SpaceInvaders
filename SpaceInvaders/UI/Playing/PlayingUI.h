#pragma once
#include "SFML/Graphics/Text.hpp"

#include "../../Models/ECS/APlayer.h"
#include "../../Models/ECS/Manager.h"
#include "../UIBase.h"

class RenderWindow;
class Game;
class Ship;
enum class SelectState;

class PlayingUI : public UIBase
{
public:
	Manager manager;
	APlayer& mPl;

	Game* m_Game;

private:
	sf::Text HpText;

public:
	PlayingUI(const sf::Vector2f playerSize, Game* mGame);
	~PlayingUI();

	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	void SetShip(SelectState state);
	void RestartGame();
};

