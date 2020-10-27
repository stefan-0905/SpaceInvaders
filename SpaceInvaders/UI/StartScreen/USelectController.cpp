#include "UTextComponent.h"
#include "SFML/Window/Keyboard.hpp"

#include "USelectController.h"

USelectController::USelectController(bool* resultSelector)
{
	StartKey = sf::Keyboard::A;
	QuitKey = sf::Keyboard::D;

	ResultSelector = resultSelector;

}

void USelectController::Init()
{
	TextComponent = &GetOwner()->GetComponent<UTextComponent>();
}

void USelectController::Tick(float DeltaTime)
{
	if ((sf::Keyboard::isKeyPressed(StartKey)) && (sf::Keyboard::isKeyPressed(QuitKey)))
	{
	}
	else if (sf::Keyboard::isKeyPressed(StartKey))
	{
		if (TextComponent->GetTitle() == L"Start")
			TextComponent->IsSelected(true);
		if (TextComponent->GetTitle() == L"Quit")
			TextComponent->IsSelected(false);

		*ResultSelector = true;
	}
	else if (sf::Keyboard::isKeyPressed(QuitKey)) {
		if (TextComponent->GetTitle() == L"Start")
			TextComponent->IsSelected(false);
		if (TextComponent->GetTitle() == L"Quit")
			TextComponent->IsSelected(true);

		*ResultSelector = false;
	}


}
