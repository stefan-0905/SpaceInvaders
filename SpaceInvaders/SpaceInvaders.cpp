#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "InvaderArmy.h"
#include "Bullet.h"
#include "Game.h"
#include "SpaceInvaders.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Space Invaders");
    window.setFramerateLimit(60);

    Game m_Game(sf::Vector2f(76.f, 48.f), window.getSize());

    float deltaTime = 0.f;
    float deltaT = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        deltaT += deltaTime;
        sf::Event event;
        
        m_Game.HandleMoving(deltaTime);
        window.clear();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    m_Game.HandleStates(event, window);
                }
               
            }
            if(event.type == sf::Event::MouseButtonPressed)
                if (event.key.code == sf::Mouse::Left)
                {
                    m_Game.Fire(deltaT);
                }
        }
        
        m_Game.HandleDrawing(window);

        window.display();
    }
}
