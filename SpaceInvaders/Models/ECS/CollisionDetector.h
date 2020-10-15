#pragma once

#include <vector>

class Entity;
class UColliderComponent;

class CollisionDetector
{
public:
	static void CheckCollision(std::vector<std::unique_ptr<Entity>>* Entities);
	static bool AABB(UColliderComponent* a, UColliderComponent* b);
};