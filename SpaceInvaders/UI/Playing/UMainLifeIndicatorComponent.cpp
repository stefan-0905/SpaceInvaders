#include "../../Models/ECS/UPositionComponent.h"
#include "../../Models/ECS/UHealthComponent.h"
#include "../../Models/ECS/APlayer.h"

#include "../../Config.h"
#include "../../Models/Utils.h"

#include "UMainLifeIndicatorComponent.h"

UMainLifeIndicatorComponent::UMainLifeIndicatorComponent(APlayer* mPl)
{
	Player = mPl;

	HealthText.setFont(Config::GetFont());
	HealthText.setCharacterSize(CharacterSize);
	HealthText.setFillColor(sf::Color::White);
}

void UMainLifeIndicatorComponent::Init()
{
	//HealthComponent = &GetOwner()->GetComponent<UHealthComponent>();
	HealthComponent = &Player->GetComponent<UHealthComponent>();
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void UMainLifeIndicatorComponent::Tick(float DeltaTime)
{
	if (!ensure(HealthComponent) || !ensure(PositionComponent)) return;

	HealthText.setString("Lives: " + std::to_string((int)HealthComponent->GetHealth()) + "/" + std::to_string((int)HealthComponent->GetMaxHealth()));
	HealthText.setPosition(PositionComponent->X(), PositionComponent->Y());
}

void UMainLifeIndicatorComponent::Draw(sf::RenderWindow& window)
{
	window.draw(HealthText);
}
