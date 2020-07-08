#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(sf::Vector2f position, int damage);
	~Bullet();

	void Draw(sf::RenderWindow& window);
	void Move(int direction);

	inline sf::Vector2f GetPosition() const { return body.getPosition(); }
	bool Intersects(sf::RectangleShape& shape);
	inline int GetDamage() const { return Damage; }
private:
	sf::Sprite body;
	int Damage;
};

