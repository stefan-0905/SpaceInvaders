#pragma once
#include <SFML\Graphics.hpp>

class StartScreenUI
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

	void Draw(sf::RenderWindow& window);
};