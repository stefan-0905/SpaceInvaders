#pragma once

#include "UIBase.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class RenderWindow;

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