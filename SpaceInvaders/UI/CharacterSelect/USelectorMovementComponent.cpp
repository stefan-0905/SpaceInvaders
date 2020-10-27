#include "SFML/Window/Keyboard.hpp"

#include "../../Constants.h"

#include "../../Models/ECS/UPositionComponent.h"
#include "USelectedStateComponent.h"
#include "SelectState.h"

#include "USelectorMovementComponent.h"

USelectorMovementComponent::USelectorMovementComponent()
{
}

void USelectorMovementComponent::Init()
{
	PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
	SelectedStateComponent = &GetOwner()->GetComponent<USelectedStateComponent>();
}

void USelectorMovementComponent::Tick(float DeltaTime)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
    {
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        PositionComponent->SetPosition(WINDOW_SIZE_X / 2 - 50, WINDOW_SIZE_Y / 2 + 100);
        SelectedStateComponent->SetState(SelectState::Slinger);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        PositionComponent->SetPosition(WINDOW_SIZE_X / 2 + 50, WINDOW_SIZE_Y / 2 + 100);
        SelectedStateComponent->SetState(SelectState::Bazooker);
    }

}
