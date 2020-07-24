#pragma once

#include <SFML/Graphics.hpp>
#include "Shape.h"

class Bullet : public Shape
{
public:
	Bullet(sf::Vector2f position, float damage);
	~Bullet();

	void Draw(sf::RenderWindow& window);
	void Move(int direction);
	bool Intersects(Shape* shape);
	inline float GetDamage() const { return Damage; }
private:
	float Damage;
};

