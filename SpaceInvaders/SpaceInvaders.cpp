#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Models\Player.h"
#include "Models\InvaderArmy.h"
#include "Models\Bullet.h"
#include "Game.h"
#include "SpaceInvaders.h"
#include "Models/EventHandler.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Space Invaders");
    window.setFramerateLimit(30);

    Game m_Game(sf::Vector2f(76.f, 48.f));

    EventHandler m_Handler(&m_Game, &window);

    float deltaTime = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        
        window.clear();

        m_Game.Tick(deltaTime);

        while (window.pollEvent(event))
        {
            m_Handler.Handle(event);
        }
        
        m_Game.HandleDrawing(window);

        window.display();
    }
}
