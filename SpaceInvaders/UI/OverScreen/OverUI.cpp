#include <SFML\Graphics\RenderWindow.hpp>

#include "../../Constants.h"
#include "../../Config.h"

#include "../StartScreen/SButton.h"
#include "../CharacterSelect/SStaticText.h"
#include "../../Models/ECS/UPositionComponent.h"
#include "../StartScreen/UTextComponent.h"

#include "OverUI.h"

OverUI::OverUI()
	: Won(false)
{
    const wchar_t* resultText = Won ? L"Congratulations, you've won!" : L"Game Over! More luck next time.";

    ResultText = &manager.AddActor<SStaticText>(resultText, WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2 - 100, sf::Color::White);

    SButton* again = &manager.AddActor<SButton>(L"Play Again",
        ResultText->GetComponent<UPositionComponent>().X() - 50,
        ResultText->GetComponent<UPositionComponent>().Y() + 100, &Selected);
    again->GetComponent<UTextComponent>().SetColor(sf::Color::Yellow);


    manager.AddActor<SButton>(L"Exit",
        ResultText->GetComponent<UPositionComponent>().X() + 50,
        ResultText->GetComponent<UPositionComponent>().Y() + 100, &Selected);

    Selected = true;
}

void OverUI::EndWith(bool won)
{
    Won = won;
}

void OverUI::Tick(float deltaTime)
{
    manager.Refresh();
    manager.Tick(deltaTime);
    
    const wchar_t* resultText = Won ? L"Congratulations, you've won!" : L"Game Over! More luck next time.";
    ResultText->GetComponent<UTextComponent>().UpdateText(resultText);
}

void OverUI::Draw(sf::RenderWindow& window)
{
    manager.Draw(window);
}


