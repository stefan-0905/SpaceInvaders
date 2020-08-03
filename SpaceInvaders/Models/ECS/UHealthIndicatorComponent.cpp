#include "UHealthComponent.h"
#include "UPositionComponent.h"
#include "USpriteComponent.h"

#include "../../Config.h"
#include "../Utils.h"

#include "UHealthIndicatorComponent.h"

UHealthIndicatorComponent::UHealthIndicatorComponent()
{
	HealthText.setFont(Config::GetFont());
	HealthText.setCharacterSize(CharacterSize);
	HealthText.setFillColor(sf::Color::White);
}

void UHealthIndicatorComponent::Init()
{
	HealthComponent = &GetOwner()->GetComponent<UHealthComponent>();
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
	SpriteComponent = &GetOwner()->GetComponent<USpriteComponent>();
}

void UHealthIndicatorComponent::Tick(float DeltaTime)
{
	if (!ensure(HealthComponent) || !ensure(PositionComponent)) return;
	
	HealthText.setString(std::to_string((int)HealthComponent->GetHealth()) + "/" + std::to_string((int)HealthComponent->GetMaxHealth()));
	HealthText.setPosition(PositionComponent->X() - SpriteComponent->GetSize().x / 2, PositionComponent->Y() - SpriteComponent->GetSize().y / 2 - CharacterSize);
}

void UHealthIndicatorComponent::Draw(sf::RenderWindow& window)
{
	window.draw(HealthText);
}
