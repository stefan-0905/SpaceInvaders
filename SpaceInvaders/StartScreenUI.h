#pragma once
#include <SFML\Graphics.hpp>
#include "UIBase.h"

class StartScreenUI : public UIBase
{
public:
	bool StartSelected;
private:
	sf::RectangleShape Banner;
	sf::Texture BannerTexture;
	sf::Text StartButton;
	sf::Text ExitButton;

public:
	StartScreenUI();
	~StartScreenUI();

	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

private:
	void InitStartButton();
	void InitExitButton();
	void InitBanner();
	void SelectStart();
	void SelectExit();
};