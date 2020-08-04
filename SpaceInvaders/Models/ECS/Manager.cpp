#include "AActor.h"
#include "Manager.h"

void Manager::Tick(float DeltaTime)
{
	for (auto& e : Entities) {
		if(e) e->Tick(DeltaTime);
	}
}
void Manager::Draw(sf::RenderWindow& window)
{
	for (auto& e : Entities) {
		if(e) e->Draw(window);
	}
}

void Manager::Refresh()
{
	Entities.erase(std::remove_if(Entities.begin(), Entities.end(), [](const std::unique_ptr<Entity>& mEntity)
		{
			return !mEntity->IsActive();
		}), Entities.end());
}