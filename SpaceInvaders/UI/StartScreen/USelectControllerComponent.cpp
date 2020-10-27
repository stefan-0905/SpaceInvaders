#include "UTextComponent.h"
#include "SFML/Window/Keyboard.hpp"

#include "../../Models/ECS/UPositionComponent.h"

#include "../../Constants.h"


#include "USelectControllerComponent.h"

USelectControllerComponent::USelectControllerComponent(bool* resultSelector)
{
	StartKey = sf::Keyboard::A;
	QuitKey = sf::Keyboard::D;

	ResultSelector = resultSelector;
}

void USelectControllerComponent::Init()
{
	TextComponent = &GetOwner()->GetComponent<UTextComponent>();
}

void USelectControllerComponent::Tick(float DeltaTime)
{
	if ((sf::Keyboard::isKeyPressed(StartKey)) && (sf::Keyboard::isKeyPressed(QuitKey)))
	{
	}
	else if (sf::Keyboard::isKeyPressed(StartKey))
	{
		if(GetOwner()->GetComponent<UPositionComponent>().X() < WINDOW_SIZE_X / 2)
			TextComponent->SetColor(sf::Color::Yellow);
		else
			TextComponent->SetColor(sf::Color::White);

		*ResultSelector = true;
	}
	else if (sf::Keyboard::isKeyPressed(QuitKey)) {
		
		if (GetOwner()->GetComponent<UPositionComponent>().X() < WINDOW_SIZE_X / 2)
			TextComponent->SetColor(sf::Color::White);
		else
			TextComponent->SetColor(sf::Color::Yellow);

		*ResultSelector = false;
	}


}
