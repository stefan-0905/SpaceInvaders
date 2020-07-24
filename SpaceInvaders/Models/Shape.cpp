#include "Shape.h"
#include "Collider.h"

Shape::Shape(float width, float height)
	: Size(width, height), Body(Size)
{
	Body.setOrigin(width / 2, height / 2);
}

void Shape::SetPosition(float x, float y)
{
	Body.setPosition(x, y);
}

void Shape::SetSize(float width, float height)
{
	Size.x = width;
	Size.y = height;
	Body.setSize(Size);
}

void Shape::SetCenteredOrigin()
{
	Body.setOrigin(Size.x / 2, Size.y / 2);
}

bool Shape::Colliding(Shape* shape)
{
	Collider collider;
	return collider.CheckCollision(this, shape);
}

void Shape::SetTexture(const sf::Texture* texture)
{
	Body.setTexture(texture);
}

void Shape::Move(float x, float y)
{
	Body.move(x, y);
}

void Shape::Draw(sf::RenderWindow& window)
{
	window.draw(Body);
}