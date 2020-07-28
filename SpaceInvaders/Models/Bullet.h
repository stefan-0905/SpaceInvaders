#pragma once

#include <SFML/Graphics.hpp>
#include "Shape.h"

class Bullet : public Shape
{
public:

	enum class Direction
	{
		Up = 0, Down
	};

	Bullet(sf::Vector2f position, float damage, Direction moveDirection);
	~Bullet();

	void Draw(sf::RenderWindow& window);
	void Move();
	inline float GetDamage() const { return Damage; }
	inline Direction GetDirection() const { return MoveDirection; }
private:
	// Damage bullet inflicts
	float Damage;
	// Direction in which bullet moves
	Direction MoveDirection;
};

