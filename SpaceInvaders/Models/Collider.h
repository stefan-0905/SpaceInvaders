#pragma once

#include "Shapes/Shape.h"

class Collider
{
public:
	Collider() = delete;
	Collider(Collider& collider) = delete;
	// Check if two Shapes overlap 
	static bool CheckCollision(Shape* shapeOne, Shape* shape);
};

bool Collider::CheckCollision(Shape* shapeOne, Shape* shape)
{
	if (!shape) return false;

	sf::Vector2f shapePos = shape->GetPosition();

	float deltaX = shapePos.x - shapeOne->GetPosition().x;
	float deltaY = shapePos.y - shapeOne->GetPosition().y;

	float totalShapesSizeX = (shapeOne->GetGlobalBounds().width) / 2 + (shape->GetGlobalBounds().width) / 2;
	float totalShapesSizeY = (shapeOne->GetGlobalBounds().height) / 2 + (shape->GetGlobalBounds().height) / 2;

	float intersectX = std::abs(deltaX) - totalShapesSizeX;
	float intersectY = std::abs(deltaY) - totalShapesSizeY;

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}

	return false;
}