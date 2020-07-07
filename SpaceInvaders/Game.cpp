#include "Game.h"


Game::Game(const sf::Vector2f playerSize, sf::Vector2u windowSize)
    : Player(sf::Vector2f(76.f, 48.f)), Army(30, 10)
{
    // Player initialization
    Player.SetTexture();
    Player.SetPosition((float)windowSize.x / 2, (float)windowSize.y - Player.GetShape().getGlobalBounds().height); 
}

Game::~Game()
{
}


void Game::HandleMoving(float deltaTime)
{
    static float totalTime = 1.f;
    totalTime += deltaTime;

    // Move Invading Army Left - Right
    Army.Move();
    Army.Fire(deltaTime);

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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (totalTime >= 1.f)
        {
            Player.Fire();
            totalTime -= 1;
        }
    }
}

void Game::HandleDrawing(sf::RenderWindow& window, sf::Text& text)
{
    if (!Player.CheckEnemyBulletCollision(Army))
    {
        printf("You lose!");
        window.close(); //TODO Show Game Over message
    }
    else {
        Player.Draw(window);
        Army.Draw(window);
    }

    text.setString(std::to_string(Player.HP) + "/" + std::to_string(Player.MaxHP));
    text.setPosition(window.getSize().x - 100.f - 50.f, 10.f);

    window.draw(text);
}
