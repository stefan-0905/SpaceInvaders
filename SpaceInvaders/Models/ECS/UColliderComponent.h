#pragma once

#include "ECS.h"
#include <SFML\Graphics\Rect.hpp>

class UPositionComponent;

class UColliderComponent : public Component
{
private:
	UPositionComponent* PositionComponent;
	sf::FloatRect Collider;

public:
	UColliderComponent(float width, float height);

	virtual void Init() override;
	virtual void Tick(float DeltaTime) override;

	inline sf::FloatRect GetCollider() const { return Collider; }
};