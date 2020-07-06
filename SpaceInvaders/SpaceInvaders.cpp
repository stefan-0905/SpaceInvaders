#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "InvaderArmy.h"
#include "Bullet.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Space Invaders");
    window.setFramerateLimit(60);
    sf::Texture DefenderTexture;
    DefenderTexture.loadFromFile("res/defender.jpg");

    sf::Texture InvaderTexture;
    InvaderTexture.loadFromFile("res/invader.png");
    
    sf::Font font;
    font.loadFromFile("fonts/micross.ttf");

    sf::Text LifeText;
    LifeText.setFont(font);
    LifeText.setCharacterSize(20);
    LifeText.setFillColor(sf::Color::White);

    Player Player(sf::Vector2f(76.f, 48.f), DefenderTexture, window.getSize());
    InvaderArmy Army(30, 10, InvaderTexture);

    int FireRate = 59;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move Invading Army Left - Right
        Army.Move();
        Army.Fire();

        // Move Player And his assets - bullets
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Player.Move(Side::Left);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Player.Move(Side::Right);
        }
        Player.MoveBullets(Army);

        // Fire player bullet
        if (FireRate < 59) FireRate++;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (FireRate >= 59)
            {
                Player.Fire();
                FireRate = 0;
            }
        }

        window.clear();

        LifeText.setString(std::to_string(Player.HP) + "/" + std::to_string(Player.MaxHP));
        LifeText.setPosition(window.getSize().x - LifeText.getGlobalBounds().width - 50.f, 10.f);

        if (!Player.CheckEnemyBulletCollision(Army))
        {
            printf("You lose!");
            window.close(); //TODO Show Game Over message
        }
        else {
            Player.Draw(window);
            Army.Draw(window);
        }

        window.draw(LifeText);
        window.display();
    }
}
