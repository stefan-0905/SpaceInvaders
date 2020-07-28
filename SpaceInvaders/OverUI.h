#pragma once
#include <SFML\Graphics.hpp>
#include "UIBase.h"

class OverUI : public UIBase
{
public:
	bool AgainSelected;
private:
	bool Won;
	sf::Text ResultText;
	sf::Text PlayAgain;
	sf::Text GoBack;
	unsigned int CharacterSize;

public:
	OverUI();
	void EndWith(bool won); 
	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

private:
	void InitResultText();
	void InitPlayAgain();
	void InitGoBack();
	void GoBackSelected();
	void PlayAgainSelected();
};

