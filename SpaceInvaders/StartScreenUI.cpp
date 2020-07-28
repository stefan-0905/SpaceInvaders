#include "StartScreenUI.h"
#include "Config.h"
#include "Constants.h"

StartScreenUI::StartScreenUI()
    : Banner(sf::Vector2f(BANNER_WIDTH, BANNER_HEIGHT))
{
    InitBanner();
    InitStartButton();
    InitExitButton();

    StartSelected = true;
}

StartScreenUI::~StartScreenUI()
{
}

void StartScreenUI::Tick(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        SelectExit();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        SelectStart();
    }
}

void StartScreenUI::Draw(sf::RenderWindow& window)
{
    window.draw(Banner);
    window.draw(StartButton);
    window.draw(ExitButton);
}

void StartScreenUI::InitStartButton()
{
    StartButton.setFont(Config::GetFont());
    StartButton.setCharacterSize(18);
    StartButton.setFillColor(sf::Color::Yellow);
    StartButton.setStyle(sf::Text::Underlined);
    StartButton.setString("Start");
    StartButton.setOrigin(StartButton.getGlobalBounds().width / 2, StartButton.getGlobalBounds().height / 2);
    StartButton.setPosition(Banner.getPosition().x - StartButton.getGlobalBounds().width, Banner.getPosition().y + Banner.getGlobalBounds().height * 2);
}

void StartScreenUI::InitExitButton()
{
    ExitButton.setFont(Config::GetFont());
    ExitButton.setCharacterSize(18);
    ExitButton.setFillColor(sf::Color::White);
    ExitButton.setString("Exit");
    ExitButton.setOrigin(ExitButton.getGlobalBounds().width / 2, ExitButton.getGlobalBounds().height / 2);
    ExitButton.setPosition(Banner.getPosition().x + ExitButton.getGlobalBounds().width, Banner.getPosition().y + Banner.getGlobalBounds().height * 2);
}

void StartScreenUI::InitBanner()
{
    BannerTexture.loadFromFile("res/title.jpg");
    Banner.setTexture(&BannerTexture);
    Banner.setOrigin(Banner.getGlobalBounds().width / 2, Banner.getGlobalBounds().height / 2);
    Banner.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);
}

void StartScreenUI::SelectStart()
{
    StartButton.setStyle(sf::Text::Underlined);
    ExitButton.setStyle(sf::Text::Regular);

    StartButton.setFillColor(sf::Color::Yellow);
    ExitButton.setFillColor(sf::Color::White);
    StartSelected = true;
}

void StartScreenUI::SelectExit()
{
    StartButton.setStyle(sf::Text::Regular);
    ExitButton.setStyle(sf::Text::Underlined);

    StartButton.setFillColor(sf::Color::White);
    ExitButton.setFillColor(sf::Color::Yellow);
    StartSelected = false;
}
