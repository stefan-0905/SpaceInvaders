#pragma once
#include <SFML\Graphics.hpp>


class OverUI
{
public:
	bool AgainSelected;
private:
	bool Won;
	sf::Text ResultText;
	sf::Text PlayAgain;
	sf::Text GoBack;

public:
	OverUI();
	void EndWith(bool won); 
	void Draw(sf::RenderWindow& window);
};

