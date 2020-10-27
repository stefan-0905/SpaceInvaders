#include "Game.h"

#include "Config.h"
#include "Constants.h"
#include "Models/ECS/Manager.h"

Game::Game(Manager& manager, const sf::Vector2f playerSize)
    /*: StartScreen(manager.AddActor<StartScreenUI>()), 
    Playing(manager.AddActor<PlayingUI>(playerSize, this)),
    CharacterSelect(manager.AddActor< CharacterSelectUI>()),
    Over(manager.AddActor<OverUI>())*/
    : Playing(playerSize, this)
{
    State = GameState::StartScreen;
    CurrentUIState = &StartScreen;
}

Game::~Game()
{
}

void Game::Tick(float deltaTime)
{
    CurrentUIState->Tick(deltaTime);
}

void Game::HandleDrawing(sf::RenderWindow& window)
{
    CurrentUIState->Draw(window);
}

void Game::HandleStates(sf::Event event, sf::RenderWindow& window)
{
    switch (State)
    {
    case GameState::StartScreen:
        if (StartScreen.StartSelected)
        {
            State = GameState::CharacterSelect;
            CurrentUIState = &CharacterSelect;
        }
        else window.close();
        break;
    case GameState::CharacterSelect:
        Playing.SetShip(CharacterSelect.GetSelectedShip());
        State = GameState::Playing;
        CurrentUIState = &Playing;
        break;
    case GameState::Playing:
        break;
    case GameState::Over:
        Playing.RestartGame();
        Over.AgainSelected ? State = GameState::Playing : State = GameState::StartScreen;
        Over.AgainSelected ? CurrentUIState = &Playing : CurrentUIState = &StartScreen;
        break;
    default:
        break;
    }
}

void Game::FinishGame(bool success)
{
    Over.EndWith(success);
    State = GameState::Over;
    CurrentUIState = &Over;
}
