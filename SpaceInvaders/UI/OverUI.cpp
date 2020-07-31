#include <SFML\Graphics\RenderWindow.hpp>

#include "../Constants.h"
#include "../Config.h"

#include "OverUI.h"

OverUI::OverUI()
	: Won(false), AgainSelected(true)
{
    CharacterSize = 36;
    
    InitResultText();
    InitPlayAgain();
    InitGoBack();
}

void OverUI::EndWith(bool won)
{
    Won = won;
}

void OverUI::Tick(float deltaTime)
{
    Won ? ResultText.setString("You Won! Congratulations!") : ResultText.setString("You Lost! Better luck next time.");

    ResultText.setOrigin(ResultText.getGlobalBounds().width / 2, ResultText.getGlobalBounds().height / 2);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        GoBackSelected();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        PlayAgainSelected();
    }
}

void OverUI::Draw(sf::RenderWindow& window)
{
    window.draw(ResultText);
    window.draw(PlayAgain);
    window.draw(GoBack);

}

void OverUI::InitResultText()
{
    ResultText.setFont(Config::GetFont());
    ResultText.setCharacterSize(CharacterSize);
    ResultText.setFillColor(sf::Color::White);
    ResultText.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
}

void OverUI::InitPlayAgain()
{
    PlayAgain.setFont(Config::GetFont());
    PlayAgain.setCharacterSize(CharacterSize / 2);
    PlayAgain.setFillColor(sf::Color::Yellow);
    PlayAgain.setStyle(sf::Text::Underlined);
    PlayAgain.setString("Play Again");
    PlayAgain.setOrigin(PlayAgain.getGlobalBounds().width, PlayAgain.getGlobalBounds().height / 2);
    PlayAgain.setPosition((float)WINDOW_SIZE_X / 2 - 10.f, (float)WINDOW_SIZE_Y / 2 + CharacterSize * 2);
}

void OverUI::InitGoBack()
{
    GoBack.setFont(Config::GetFont());
    GoBack.setCharacterSize(CharacterSize / 2);
    GoBack.setFillColor(sf::Color::White);
    GoBack.setString("Exit");
    GoBack.setOrigin(0.f, GoBack.getGlobalBounds().height / 2);
    GoBack.setPosition((float)WINDOW_SIZE_X / 2 + 10.f, (float)WINDOW_SIZE_Y / 2 + CharacterSize * 2);
}

void OverUI::GoBackSelected()
{
    PlayAgain.setStyle(sf::Text::Regular);
    GoBack.setStyle(sf::Text::Underlined);

    PlayAgain.setFillColor(sf::Color::White);
    GoBack.setFillColor(sf::Color::Yellow);

    AgainSelected = false;
}

void OverUI::PlayAgainSelected()
{
    PlayAgain.setStyle(sf::Text::Underlined);
    GoBack.setStyle(sf::Text::Regular);

    PlayAgain.setFillColor(sf::Color::Yellow);
    GoBack.setFillColor(sf::Color::White);

    AgainSelected = true;
}
