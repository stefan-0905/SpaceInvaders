#include "SFML/Graphics/RenderWindow.hpp";
#include "SFML/System/Clock.hpp"
#include "SFML/Window/Event.hpp"

#include "Game.h"
#include "EventHandler.h"
#include "SpaceInvaders.h"

#include "Models/ECS/APlayer.h"
#include "Spawner.h"

Manager m_Manager;
auto& m_Player(m_Manager.AddActor<APlayer>(50.f, 50.f, "res/Slinger.png", &m_Manager));

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Space Invaders");
    
    Game m_Game(sf::Vector2f(76.f, 48.f));
    EventHandler m_Handler(&m_Game, &window);

    Spawner::Spawn(20, &m_Manager);
   
    float deltaTime = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        
        window.clear();
        m_Manager.Refresh();

        m_Manager.Tick(deltaTime);

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
