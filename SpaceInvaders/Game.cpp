#include "Game.h"

#include "Config.h"
#include "Constants.h"

Game::Game(const sf::Vector2f playerSize)
    : Playing(playerSize)
{
    State = GameState::StartScreen;
    CurrentState = &StartScreen;
}

Game::~Game()
{
}

void Game::Tick(float deltaTime)
{
    CurrentState->Tick(deltaTime);

    if (State != GameState::Playing) return;
    if (!Playing.m_Player.Alive())
    {
        Over.EndWith(false);
        State = GameState::Over;
        CurrentState = &Over;
    }
    else {
        if (Playing.m_Level.GetCurrentLevel() > Level::MaxLevel)
        {
            Over.EndWith(true);
            State = GameState::Over;
            CurrentState = &Over;
        }
    }
}

void Game::HandleDrawing(sf::RenderWindow& window)
{
    CurrentState->Draw(window);
}

void Game::HandleStates(sf::Event event, sf::RenderWindow& window)
{
    switch (State)
    {
    case GameState::StartScreen:
        if (StartScreen.StartSelected)
        {
            State = GameState::CharacterSelect;
            CurrentState = &CharacterSelect;
        }
        else window.close();
        break;
    case GameState::CharacterSelect:
        Playing.SetShip(CharacterSelect.GetSelectedShip());
        State = GameState::Playing;
        CurrentState = &Playing;
        break;
    case GameState::Playing:
        break;
    case GameState::Over:
        Playing.RestartGame();
        Over.AgainSelected ? State = GameState::Playing : State = GameState::StartScreen;
        Over.AgainSelected ? CurrentState = &Playing : CurrentState = &StartScreen;
        break;
    default:
        break;
    }
}