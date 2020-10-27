#pragma once

#include <vector>
#include <memory>
#include "SFML/Graphics/RenderWindow.hpp"

class Entity;
class AActor;

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> Entities;

public:
	void Tick(float DeltaTime);
	void Draw(sf::RenderWindow& window);
	
	//Empty managed entities
	void Refresh();

	template <typename T, typename... TArgs>
	T& AddActor(TArgs&&... mArgs);
};

template<typename T, typename... TArgs>
inline T& Manager::AddActor(TArgs&&... mArgs)
{
	T* e = new T(std::forward<TArgs>(mArgs)...);
	std::unique_ptr<T> uPtr(e);
	Entities.emplace_back(std::move(uPtr));

	return *e;
}
