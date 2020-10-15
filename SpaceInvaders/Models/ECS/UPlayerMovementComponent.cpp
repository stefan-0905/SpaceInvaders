#include "SFML/Window/Keyboard.hpp"
#include "UPositionComponent.h"
#include "UCombatComponent.h"
#include "UPlayerMovementComponent.h"
#include "../../Constants.h"

UPlayerMovementComponent::UPlayerMovementComponent()
{
    MaxVelocity = 200.f;
    VelocityX = 200.f;
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
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    {
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) acceleration = -VelocityX;// -Acceleration;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) acceleration = VelocityX;// Acceleration;

    //// If no key pressed, gradually stop player movement
    //if (acceleration == 0) 
    //{
    //    if (VelocityX > 0) {
    //        // Stopping twice as fast then starting to move
    //        acceleration = -Acceleration*2;
    //        VelocityX += acceleration;
    //        if (VelocityX < 0) VelocityX = 0;
    //    }
    //    if (VelocityX < 0) {
    //        acceleration = Acceleration*2;
    //        VelocityX += acceleration;
    //        if (VelocityX > 0) VelocityX = 0;
    //    }
    //}
    //else
    //{
    //    VelocityX += acceleration;
    //}
    //VelocityX += acceleration;

    //if (VelocityX >= MaxVelocity) VelocityX = MaxVelocity;
    //else if (VelocityX <= -MaxVelocity) VelocityX = -MaxVelocity;

    PositionComponent->Move(acceleration * DeltaTime, 0.0f);

    if (PositionComponent->X() < 50.f)
    {
        PositionComponent->SetPosition(50.f, PositionComponent->Y());
        //VelocityX = 0.f;
    }

    if (PositionComponent->X() > WINDOW_SIZE_X - 50.f)
    {
        PositionComponent->SetPosition(WINDOW_SIZE_X - 50.f, PositionComponent->Y());
        //VelocityX = 0.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        GetOwner()->GetComponent<UCombatComponent>().Fire();
    }

}
