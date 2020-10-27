#pragma once

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Color.hpp"

class Texture;
class RenderWindow;

class Shape
{
protected:
	sf::Vector2f Size;
	sf::RectangleShape Body;
public:
	Shape() = delete;
	Shape(float width, float height);

	// Get texture
	inline const sf::Texture* GetTexture() { return Body.getTexture(); }
	// Get the position of a shape
	inline sf::Vector2f GetPosition() const { return Body.getPosition(); }
	// Get the size of a shape
	inline sf::FloatRect GetGlobalBounds() const { return Body.getGlobalBounds(); }
	// Set position of a shape
	void SetPosition(float x, float y);
	// Set size of a shape
	void SetSize(float width, float height);
	// Set fill color
	void SetFillColor(sf::Color color);
	// Set origin as centered
	void SetCenteredOrigin();
	// Check if shape intersects with shape
	bool Intersects(Shape* shape);
	//Set texture
	void SetTexture(const sf::Texture* texture);
	// Move shape
	virtual void Move(float x, float y);
	// Draw shape
	virtual void Draw(sf::RenderWindow& window);
};