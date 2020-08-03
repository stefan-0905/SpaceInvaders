#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"

#include "Game.h"
#include "EventHandler.h"
#include "SpaceInvaders.h"

#include "Models/ECS/AActor.h"
#include "Models/ECS/Manager.h"
#include "Models/ECS/UPositionComponent.h"
#include "Models/ECS/USpriteComponent.h"
#include "Models/ECS/UHealthComponent.h"
#include "Models/ECS/UHealthIndicatorComponent.h"

Manager m_Manager;
AActor& m_Player(m_Manager.AddActor());

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Space Invaders");
    window.setFramerateLimit(30);

    Game m_Game(sf::Vector2f(76.f, 48.f));

    EventHandler m_Handler(&m_Game, &window);

    m_Player.AddComponent<UPositionComponent>(50.f, 50.f);
    m_Player.AddComponent<USpriteComponent>(50.f, 50.f, "res/Slinger.png");
    m_Player.AddComponent<UHealthComponent>(3.f);
    m_Player.AddComponent<UHealthIndicatorComponent>();

    float deltaTime = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        
        m_Manager.Tick(deltaTime);
        
        window.clear();

        m_Game.Tick(deltaTime);

        while (window.pollEvent(event))
        {
            m_Handler.Handle(event);
        }
        
        m_Manager.Draw(window);
        m_Game.HandleDrawing(window);

        window.display();
    }
}
