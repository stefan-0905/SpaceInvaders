#include "OverUI.h"

#include "Config.h"

OverUI::OverUI()
	: Won(false), AgainSelected(true)
{
    ResultText.setFont(Config::GetFont());
    ResultText.setCharacterSize(36);
    ResultText.setFillColor(sf::Color::White);

    PlayAgain.setFont(Config::GetFont());
    PlayAgain.setCharacterSize(18);
    PlayAgain.setFillColor(sf::Color::Yellow);
    PlayAgain.setStyle(sf::Text::Underlined);
    PlayAgain.setString("Play Again");
    PlayAgain.setOrigin(PlayAgain.getGlobalBounds().width, PlayAgain.getGlobalBounds().height / 2);

    GoBack.setFont(Config::GetFont());
    GoBack.setCharacterSize(18);
    GoBack.setFillColor(sf::Color::White);
    GoBack.setString("Exit");
    GoBack.setOrigin(0.f, GoBack.getGlobalBounds().height / 2);
}

void OverUI::EndWith(bool won)
{
    Won = true;
}

void OverUI::Draw(sf::RenderWindow& window)
{
    Won ? ResultText.setString("You Won! Congratulations!") : ResultText.setString("You Lost! Better luck next time.");

    ResultText.setOrigin(ResultText.getGlobalBounds().width / 2, ResultText.getGlobalBounds().height / 2);
    ResultText.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);

    PlayAgain.setPosition(ResultText.getPosition().x - 10.f, ResultText.getPosition().y + ResultText.getGlobalBounds().height * 2);
    GoBack.setPosition(ResultText.getPosition().x + 10.f, ResultText.getPosition().y + ResultText.getGlobalBounds().height * 2);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        PlayAgain.setStyle(sf::Text::Regular);
        GoBack.setStyle(sf::Text::Underlined);

        PlayAgain.setFillColor(sf::Color::White);
        GoBack.setFillColor(sf::Color::Yellow);

        AgainSelected = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        PlayAgain.setStyle(sf::Text::Underlined);
        GoBack.setStyle(sf::Text::Regular);

        PlayAgain.setFillColor(sf::Color::Yellow);
        GoBack.setFillColor(sf::Color::White);

        AgainSelected = true;
    }

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    //{
    //    //RestartGame();
    //    if (AgainSelected)
    //    {
    //        State = GameState::Playing;
    //    }
    //    else
    //    {
    //        State = GameState::StartScreen;
    //    }
    //}

    window.draw(ResultText);
    window.draw(PlayAgain);
    window.draw(GoBack);

}
