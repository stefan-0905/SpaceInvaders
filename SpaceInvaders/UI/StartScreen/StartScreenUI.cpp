#include "SFML/Graphics/RenderWindow.hpp"

#include "../../Constants.h"
#include "../../Config.h"

#include "SBanner.h"
#include "SButton.h"
#include "../../Models/ECS/UPositionComponent.h"
#include "UTextComponent.h"

#include "StartScreenUI.h"

StartScreenUI::StartScreenUI()
{
    Banner = &manager.AddActor<SBanner>();
    SButton* Start = &manager.AddActor<SButton>(L"Start", Banner->GetComponent<UPositionComponent>().X() - 50, Banner->GetComponent<UPositionComponent>().Y() + 100, &StartSelected);
    Start->GetComponent<UTextComponent>().SetColor(sf::Color::Yellow);
    manager.AddActor<SButton>(L"Quit", Banner->GetComponent<UPositionComponent>().X() + 50, Banner->GetComponent<UPositionComponent>().Y() + 100, &StartSelected);

    StartSelected = true;
}

StartScreenUI::~StartScreenUI()
{
}

void StartScreenUI::Tick(float deltaTime)
{
    manager.Refresh();
    manager.Tick(deltaTime);
}

void StartScreenUI::Draw(sf::RenderWindow& window)
{
    manager.Draw(window);
}