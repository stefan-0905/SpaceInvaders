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

    sf::Font font;
    font.loadFromFile("fonts/micross.ttf");

    sf::Text LifeText;
    LifeText.setFont(font);
    LifeText.setCharacterSize(20);
    LifeText.setFillColor(sf::Color::White);

    Game m_Game(sf::Vector2f(76.f, 48.f), window.getSize());

    float deltaTime = 0.f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        m_Game.HandleMoving(deltaTime);
        
        window.clear();

        m_Game.HandleDrawing(window, LifeText);

        window.display();
    }
}
