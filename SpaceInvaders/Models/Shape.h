#pragma once

#include "SFML/Graphics.hpp"

class Shape
{
protected:
	sf::Vector2f Size;
	sf::RectangleShape Body;
public:
	Shape() = delete;
	Shape(float width, float height);

	inline const sf::Texture* GetTexture() { return Body.getTexture(); }
	// Get the position of a shape
	inline sf::Vector2f GetPosition() const { return Body.getPosition(); }
	// Get the size of a shape
	inline sf::FloatRect GetGlobalBounds() const { return Body.getGlobalBounds(); }
	// Set position of a shape
	void SetPosition(float x, float y);
	// Set size of a shape
	void SetSize(float width, float height);

	void SetFillColor(sf::Color color);

	void SetCenteredOrigin();
	virtual bool Colliding(Shape* shape);

	void SetTexture(const sf::Texture* texture);
	// Move shape
	virtual void Move(float x, float y);
	// Draw shape
	virtual void Draw(sf::RenderWindow& window);
};