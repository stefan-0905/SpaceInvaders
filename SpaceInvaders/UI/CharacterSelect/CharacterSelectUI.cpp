#include "SFML/Graphics/RenderWindow.hpp"

#include "../../Config.h"
#include "../../Constants.h"

#include "../StartScreen/UTextComponent.h"
#include "SImage.h"
#include "SStaticText.h"
#include "SSelector.h"

#include "CharacterSelectUI.h"


CharacterSelectUI::CharacterSelectUI()
{
	manager.AddActor<SStaticText>(L"Select You Ship:", WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2 - 100, sf::Color::Yellow);

	manager.AddActor<SImage>("res/Slinger.png", 50.F, 100.F, WINDOW_SIZE_X / 2 - 50, WINDOW_SIZE_Y / 2);
	manager.AddActor<SImage>("res/Bazooker.png", 50.F, 100.F, WINDOW_SIZE_X / 2 + 50, WINDOW_SIZE_Y / 2);

	Selector = &manager.AddActor<SSelector>();

}

CharacterSelectUI::~CharacterSelectUI()
{
}

void CharacterSelectUI::Tick(float deltaTime)
{
	manager.Refresh();
	manager.Tick(deltaTime);
}

void CharacterSelectUI::Draw(sf::RenderWindow& window)
{
	manager.Draw(window);
}

const SelectState& CharacterSelectUI::GetSelectedShip() const
{
	return Selector->GetState();
}
