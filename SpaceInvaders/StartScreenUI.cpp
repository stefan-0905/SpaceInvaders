#include "StartScreenUI.h"
#include "Config.h"
#include "Constants.h"

StartScreenUI::StartScreenUI()
    : Banner(sf::Vector2f(BANNER_WIDTH, BANNER_HEIGHT))
{
    //Font.loadFromFile("fonts/micross.ttf");
    BannerTexture.loadFromFile("res/title.jpg");

    Banner.setTexture(&BannerTexture);

    StartButton.setFont(Config::GetFont());
    StartButton.setCharacterSize(18);
    StartButton.setFillColor(sf::Color::Yellow);
    StartButton.setStyle(sf::Text::Underlined);
    StartButton.setString("Start");
    StartButton.setOrigin(StartButton.getGlobalBounds().width / 2, StartButton.getGlobalBounds().height / 2);

    StartSelected = true;

    ExitButton.setFont(Config::GetFont());
    ExitButton.setCharacterSize(18);
    ExitButton.setFillColor(sf::Color::White);
    ExitButton.setString("Exit");
    ExitButton.setOrigin(ExitButton.getGlobalBounds().width / 2, ExitButton.getGlobalBounds().height / 2);

}

StartScreenUI::~StartScreenUI()
{
}

void StartScreenUI::Draw(sf::RenderWindow& window)
{
    Banner.setOrigin(Banner.getGlobalBounds().width / 2, Banner.getGlobalBounds().height / 2);
    Banner.setPosition((float)window.getSize().x / 2, (float)window.getSize().y / 2);

    StartButton.setPosition(Banner.getPosition().x - StartButton.getGlobalBounds().width, Banner.getPosition().y + Banner.getGlobalBounds().height * 2);
    ExitButton.setPosition(Banner.getPosition().x + ExitButton.getGlobalBounds().width, Banner.getPosition().y + Banner.getGlobalBounds().height * 2);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        StartButton.setString("Start");
        ExitButton.setString("Exit");

        StartButton.setStyle(sf::Text::Regular);
        ExitButton.setStyle(sf::Text::Underlined);

        StartButton.setFillColor(sf::Color::White);
        ExitButton.setFillColor(sf::Color::Yellow);
        StartSelected = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        StartButton.setString("Start");
        ExitButton.setString("Exit");
        StartButton.setStyle(sf::Text::Underlined);
        ExitButton.setStyle(sf::Text::Regular);


        StartButton.setFillColor(sf::Color::Yellow);
        ExitButton.setFillColor(sf::Color::White);
        StartSelected = true;
    }

    window.draw(Banner);
    window.draw(StartButton);
    window.draw(ExitButton);
}
