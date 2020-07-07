#pragma once

#include <SFML/Graphics.hpp>

enum class Side {
	Left = 0, Right
};

class Invader
{
public:
	Invader(sf::Vector2f position);

	void Draw(sf::RenderWindow& window);
	void Move(Side side);
	void SetTexture();
	sf::Vector2f GetPosition() const { return body.getPosition();}
	sf::Sprite& GetShape() { return body; };

public:
	bool Killed = false;
private:
	sf::Texture* InvaderTexture;
	sf::Sprite body;
	bool Left;
};

