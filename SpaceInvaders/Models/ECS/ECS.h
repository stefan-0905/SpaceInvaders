#pragma once

#include <memory>
#include <bitset>
#include <array>
#include <vector>
#include <algorithm>
#include <SFML\Graphics\RenderWindow.hpp>


class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	// ID of last component
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
protected:
	Entity* entity;

public:
	Entity* GetOwner() { return entity; }
	void SetOwner(Entity* owner) { entity = owner; }
	virtual void Init() {}
	virtual void Tick(float DeltaTime) {}
	virtual void Draw(sf::RenderWindow& window) {}

	virtual ~Component() {}

private:
};

class Entity
{
private:
	bool Active = true;
	std::vector<std::unique_ptr<Component>> Components;

	ComponentArray ComponentArray;
	ComponentBitSet ComponentBitSet;

public:
	void Tick(float DeltaTime)
	{
		for (auto& c : Components) c->Tick(DeltaTime);
	}
	void Draw(sf::RenderWindow& window)
	{
		for (auto& c : Components) c->Draw(window);
	}

	bool IsActive() const { return Active; }
	void Destroy() { Active = false; }

	template <typename T> bool HasComponent() const
	{
		return ComponentBitSet[GetComponentTypeID<T>];
	}

	template <typename T, typename... TArgs> 
	T& AddComponent(TArgs&&... mArgs)
	{
		T* NewComponent = new T(std::forward<TArgs>(mArgs)...);

		NewComponent->SetOwner(this);
		std::unique_ptr<Component> uPtr(NewComponent);
		Components.emplace_back(std::move(uPtr));

		ComponentArray[GetComponentTypeID<T>()] = NewComponent;
		ComponentBitSet[GetComponentTypeID<T>()] = true;

		NewComponent->Init();

		return *NewComponent;
	}

	template<typename T> T& GetComponent() const
	{
		auto ptr(ComponentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

