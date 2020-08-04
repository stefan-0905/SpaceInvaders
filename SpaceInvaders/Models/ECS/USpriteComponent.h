#pragma once

#include "ECS.h"

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class UPositionComponent;

class USpriteComponent : public Component
{
private:
	UPositionComponent* PositionComponent;
	sf::Texture Texture;

	sf::RectangleShape Body;

public:
	USpriteComponent();
	USpriteComponent(float size_x, float size_y, const char* path = nullptr);

	inline sf::Vector2f GetSize() const { return Body.getSize(); }

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetTexture(const char* path);
};

