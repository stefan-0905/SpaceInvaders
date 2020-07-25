#include "Game.h"

#include "Config.h"

Game::Game(const sf::Vector2f playerSize, sf::Vector2u windowSize)
    : m_Player(sf::Vector2f(76.f, 48.f)), Army(30), cLevel(&Army), Font(Config::GetFont())
{
    State = GameState::StartScreen;
    // Player initialization
    m_Player.SetPosition((float)windowSize.x / 2, (float)windowSize.y - m_Player.GetSize().y);

    HpText.setFont(Font);
    HpText.setCharacterSize(20);
    HpText.setFillColor(sf::Color::White);
}

Game::~Game()
{
}

void Game::HandleMoving(float deltaTime)
{
    if (State != GameState::Playing) return;

    if (cLevel.Completed())
    {
        cLevel.Next();
    }

    // Move Invading Army Left - Right
    Army.Move();
    Army.Fire(deltaTime);

    // Move Player And his assets - bullets
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_Player.Move(Side::Left);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_Player.Move(Side::Right);
    } 
    m_Player.MoveBullets(Army);


}

void Game::Fire(float& deltaTime)
{
    if (deltaTime >= m_Player.GetFireRate())
    {
        m_Player.Fire();
        deltaTime = 0;
    }
}

void Game::HandleDrawing(sf::RenderWindow& window)
{
    switch (State)
    {
    case GameState::StartScreen:
        DrawStartScreen(window);
        break;
    case GameState::CharacterSelect:
        DrawCharacherSelect(window);
        break;
    case GameState::Playing:
        DrawPlaying(window);
        break;
    case GameState::Over:
        DrawOver(window);
        break;
    default:
        break;
    }
    
}
void Game::DrawPlaying(sf::RenderWindow& window)
{
    //if (!m_Player.CheckEnemyBulletCollision(&Army))
    if (!m_Player.CheckEnemyBulletCollision(&Army))
    {
        Over.EndWith(false);
        State = GameState::Over;
    }
    else {
        if (cLevel.GetCurrentLevel() == 4)
        {
            Over.EndWith(true);
            State = GameState::Over;
        }

        m_Player.Draw(window);
        Army.Draw(window);
    }

    HpText.setString("Lives:" + std::to_string((int)m_Player.GetHP()) + "/" + std::to_string(m_Player.GetMaxHP()));
    HpText.setPosition(window.getSize().x - 100.f - 50.f, 10.f);

    window.draw(HpText);
}

void Game::HandleStates(sf::Event event, sf::RenderWindow& window)
{
    switch (State)
    {
    case GameState::StartScreen:
        if(StartScreen.StartSelected) State = GameState::CharacterSelect; else window.close();
        break;
    case GameState::CharacterSelect:
        m_Player.SetShip(CharacterSelect.GetSelectedShip());
        State = GameState::Playing;
        break;
    case GameState::Playing:
        break;
    case GameState::Over:
        RestartGame();
        Over.AgainSelected ? State = GameState::Playing : State = GameState::StartScreen;
        break;
    default:
        break;
    }
}

void Game::DrawStartScreen(sf::RenderWindow& window)
{
    StartScreen.Draw(window);
}

void Game::DrawCharacherSelect(sf::RenderWindow& window)
{
    CharacterSelect.Draw(window);
}

void Game::DrawOver(sf::RenderWindow& window)
{
    Over.Draw(window);
}

void Game::RestartGame()
{
    cLevel.StartNewGame();
    m_Player.ResetShip();
    m_Player.CleanBullets();
}