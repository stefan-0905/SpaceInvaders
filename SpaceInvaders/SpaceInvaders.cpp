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

    Game m_Game(sf::Vector2f(76.f, 48.f), window.getSize());

    EventHandler m_Handler(&m_Game, &window);

    float deltaTimeForEachFrame = 0.f;
    float deltaTimeWhenUserTriesToFire = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTimeForEachFrame = clock.restart().asSeconds();
        deltaTimeWhenUserTriesToFire += deltaTimeForEachFrame;
        sf::Event event;
        
        window.clear();

        m_Game.Tick(deltaTimeForEachFrame);

        while (window.pollEvent(event))
        {
            m_Handler.Handle(event, deltaTimeWhenUserTriesToFire);
        }
        
        m_Game.HandleDrawing(window);

        window.display();
    }
}
