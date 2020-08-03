#include "AActor.h"

#include "Manager.h"

void Manager::Tick(float DeltaTime)
{
	for (auto& e : Entities) e->Tick(DeltaTime);
}
void Manager::Draw(sf::RenderWindow& window)
{
	for (auto& e : Entities) e->Draw(window);
}

void Manager::Refresh()
{
	Entities.erase(std::remove_if(Entities.begin(), Entities.end(), [](const std::unique_ptr<Entity>& mEntity)
		{
			return mEntity->IsActive();
		}), Entities.end());
}

Entity& Manager::AddEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr(e);
	Entities.emplace_back(std::move(uPtr));

	return *e;
}

AActor& Manager::AddActor()
{
	AActor* e = new AActor();
	std::unique_ptr<AActor> uPtr(e);
	Entities.emplace_back(std::move(uPtr));

	return *e;
}