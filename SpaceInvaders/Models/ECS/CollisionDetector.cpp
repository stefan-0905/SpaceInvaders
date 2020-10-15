#include "UColliderComponent.h"
#include <vector>
#include "UHealthComponent.h"
#include "CollisionDetector.h"

void CollisionDetector::CheckCollision(std::vector<std::unique_ptr<Entity>>* Entities)
{
	//TODO Consider optimizing check
	for (size_t i = 0; i < Entities->size(); i++)
	{
		// If by any case, the pointer was lost. Skip it
		if (!Entities->at(i)) continue;

		if (Entities->at(i)->HasComponent<UColliderComponent>() &&
			Entities->at(i)->HasComponent<UHealthComponent>() && // If it has UHealthComponent then it an killable object
			// Each object can destroy maximum one other object.
			// As we iterate through entities, we need to keep checking if the object was not already destroyed
			// In one of the previous iterations. Because the real deletion will happen in next frame.
			// There for the neccessity for the IsKilled() method.
			!Entities->at(i)->GetComponent<UHealthComponent>().IsKilled())
			for (size_t j = 0; j < Entities->size(); j++)
			{
				if (i != j 
					&& !Entities->at(j)->HasComponent<UHealthComponent>() // If it doesn't have UHeathComponent, it's a bullet
					&& Entities->at(j)->HasComponent<UColliderComponent>())
				{
					if (CollisionDetector::AABB(
						&Entities->at(i)->GetComponent<UColliderComponent>(),
						&Entities->at(j)->GetComponent<UColliderComponent>()
					))
					{
						Entities->at(i)->Destroy();
						Entities->at(j)->Destroy();
					}
				}
			}

	}
}

bool CollisionDetector::AABB(UColliderComponent* a, UColliderComponent* b)
{
	if (!a || !b) return false;

	float deltaX = a->GetCollider().left - b->GetCollider().left;
	float deltaY = a->GetCollider().top - b->GetCollider().top;

	float totalShapesSizeX = (a->GetCollider().width) / 2 + (b->GetCollider().width) / 2;
	float totalShapesSizeY = (a->GetCollider().height) / 2 + (b->GetCollider().height) / 2;

	float intersectX = std::abs(deltaX) - totalShapesSizeX;
	float intersectY = std::abs(deltaY) - totalShapesSizeY;

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		return true;
	}

	return false;
}
