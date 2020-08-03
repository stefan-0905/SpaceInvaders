#pragma once

#include <vector>
#include <memory>

class Entity;
class AActor;

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> Entities;

public:
	void Tick(float DeltaTime);
	void Draw(sf::RenderWindow& window);
	void Refresh();

	Entity& AddEntity();
	AActor& AddActor();
};
