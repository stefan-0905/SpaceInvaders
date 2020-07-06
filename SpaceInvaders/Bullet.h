#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(sf::Vector2f position);
	~Bullet();

	void Draw(sf::RenderWindow& window);
	void Move(int direction);

	inline sf::Vector2f GetPosition() const { return body.getPosition(); }
	bool Intersects(sf::Sprite& shape);
private:
	sf::Sprite body;
};

