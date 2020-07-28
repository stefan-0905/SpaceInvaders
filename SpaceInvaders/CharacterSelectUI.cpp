#include "CharacterSelectUI.h"
#include "Config.h"
#include "Constants.h"


CharacterSelectUI::CharacterSelectUI()
	: Selector(CS_SHIP_WIDTH, 5.f)
{
	InitShips();

	InitSelector();

	InitTitle();

	ShipIndex = 0;
	SelectedShip = Ships[ShipIndex];
}

CharacterSelectUI::~CharacterSelectUI()
{
	for (unsigned int i = 0; i < CS_NUMBER_OF_SHIPS; i++)
		delete Ships[i];
}

void CharacterSelectUI::Tick(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (ShipIndex < CS_NUMBER_OF_SHIPS - 1)
			++ShipIndex;
		Selector.SetPosition(WINDOW_SIZE_X / 2 + 50.f, WINDOW_SIZE_Y / 2 + 60.f);
		SelectedShip = Ships[ShipIndex];
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (ShipIndex > 0)
			--ShipIndex;
		Selector.SetPosition(WINDOW_SIZE_X / 2 - 50.f, WINDOW_SIZE_Y / 2 + 60.f);
		SelectedShip = Ships[ShipIndex];
	}
}

void CharacterSelectUI::Draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < CS_NUMBER_OF_SHIPS; i++)
	{
		Ships[i]->Draw(window);
	}

	window.draw(Title);
	Selector.Draw(window);
}

void CharacterSelectUI::InitTitle()
{
	Title.setFont(Config::GetFont());
	Title.setCharacterSize(24);
	Title.setString("Select You Ship:");
	Title.setFillColor(sf::Color::Yellow);
	Title.setOrigin(Title.getGlobalBounds().width / 2, Title.getGlobalBounds().height / 2);
	Title.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2 - 100.f);
}

void CharacterSelectUI::InitShips()
{
	Ships[0] = new Slinger(CS_SHIP_WIDTH, CS_SHIP_HEIGHT);
	Ships[1] = new Bazooker(CS_SHIP_WIDTH, CS_SHIP_HEIGHT);

	float startX = WINDOW_SIZE_X / 2 - CS_NUMBER_OF_SHIPS / 2 * 50.f;
	float startY = WINDOW_SIZE_Y / 2;

	for (unsigned int i = 0; i < CS_NUMBER_OF_SHIPS; i++)
	{
		Ships[i]->SetPosition(startX, startY);
		startX += 100.f;
	}
}

void CharacterSelectUI::InitSelector()
{
	sf::Texture texture;
	if (texture.create(static_cast<unsigned int>(CS_SHIP_WIDTH), 5))
		Selector.SetTexture(&texture);

	Selector.SetFillColor(sf::Color::Yellow);
	Selector.SetPosition(WINDOW_SIZE_X / 2 - CS_NUMBER_OF_SHIPS / 2 * CS_SHIP_WIDTH, WINDOW_SIZE_Y / 2 + CS_SHIP_HEIGHT / 2 + 10.f);
}
