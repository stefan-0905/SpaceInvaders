#include "SFML/Window/Keyboard.hpp"
#include "UPositionComponent.h"
#include "UCombatComponent.h"
#include "UPlayerMovementComponent.h"
#include "../../Constants.h"

UPlayerMovementComponent::UPlayerMovementComponent()
{
    MaxVelocity = 200.f;
    VelocityX = 0.f;
    Acceleration = 0.1f;
}

void UPlayerMovementComponent::Init()
{
    PositionComponent = &GetOwner()->GetComponent<UPositionComponent>();
}

void UPlayerMovementComponent::Tick(float DeltaTime)
{
    if (!PositionComponent) return;

    float acceleration = 0; // No key pressed
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    { }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) acceleration = -Acceleration;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) acceleration = Acceleration;

    // If no key pressed, gradually stop player movement
    if (acceleration == 0) 
    {
        if (VelocityX > 0) {
            // Stopping twice as fast then starting to move
            acceleration = -Acceleration*2;
            VelocityX += acceleration;
            if (VelocityX < 0) VelocityX = 0;
        }
        if (VelocityX < 0) {
            acceleration = Acceleration*2;
            VelocityX += acceleration;
            if (VelocityX > 0) VelocityX = 0;
        }
    }
    else
    {
        VelocityX += acceleration;
    }

    if (VelocityX > MaxVelocity) VelocityX = MaxVelocity;
    else if (VelocityX < -MaxVelocity) VelocityX = -MaxVelocity;

    PositionComponent->Move(VelocityX * DeltaTime, 0.0f);

    if (PositionComponent->X() < 50.f)
        PositionComponent->SetPosition(50.f, PositionComponent->Y());

    if (PositionComponent->X() > WINDOW_SIZE_X - 50.f)
        PositionComponent->SetPosition(WINDOW_SIZE_X - 50.f, PositionComponent->Y());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        GetOwner()->GetComponent<UCombatComponent>().Fire();
    }

}
