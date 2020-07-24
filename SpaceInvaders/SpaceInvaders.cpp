#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Models\Player.h"
#include "Models\InvaderArmy.h"
#include "Models\Bullet.h"
#include "Game.h"
#include "SpaceInvaders.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Space Invaders");
    window.setFramerateLimit(30);

    Game m_Game(sf::Vector2f(76.f, 48.f), window.getSize());

    float deltaTimeForEachFrame = 0.f;
    float deltaTimeWhenUserTriesToFire = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTimeForEachFrame = clock.restart().asSeconds();
        deltaTimeWhenUserTriesToFire += deltaTimeForEachFrame;
        sf::Event event;
        
        m_Game.HandleMoving(deltaTimeForEachFrame);
        window.clear();

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Enter)
                {
                    m_Game.HandleStates(event, window);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.key.code == sf::Mouse::Left)
                {
                    m_Game.Fire(deltaTimeWhenUserTriesToFire);
                }
                break;
            default:
                break;
            }
        }
        
        m_Game.HandleDrawing(window);

        window.display();
    }
}
