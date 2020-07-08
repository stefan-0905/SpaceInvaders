#include "CharacterSelectUI.h"
#include "Config.h"


CharacterSelectUI::CharacterSelectUI()
	: Selector(sf::Vector2f(50.f, 5.f))
{
	this->Ships.reserve(2);
	this->Ships.emplace_back(Slinger(50.f, 100.f));
	this->Ships.emplace_back(Bazooker(50.f, 100.f));

	Selector.setFillColor(sf::Color::Yellow);
	Selector.setOrigin(25.f, 2.5f);

	Selector.setPosition(1024 / 2 - Ships.size() / 2 * 50.f, 512 / 2 + 100.f / 2 + 10.f);

	SelectedShip = &(Ships[0]);
	ShipIndex = 0;

	Title.setFont(Config::GetFont());
	Title.setCharacterSize(24);
	Title.setString("Select You Ship:");
	Title.setFillColor(sf::Color::Yellow);
	Title.setOrigin(Title.getGlobalBounds().width / 2, Title.getGlobalBounds().height / 2);
}

CharacterSelectUI::~CharacterSelectUI()
{
}

void CharacterSelectUI::Draw(sf::RenderWindow& window)
{
	Title.setPosition((float)window.getSize().x / 2, window.getSize().y / 2 - 100.f);
	
	float startX = window.getSize().x / 2 - Ships.size() / 2 * 50.f;
	float startY = (float)window.getSize().y / 2;

	for (unsigned int i = 0; i < Ships.size(); i++)
	{
		Ships[i].SetPosition(startX, startY);
		startX += 100.f;
		Ships[i].Draw(window);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(ShipIndex < Ships.size() - 1)
			++ShipIndex;
		Selector.setPosition(window.getSize().x / 2 + 50.f, window.getSize().y / 2 + 60.f);
		SelectedShip = &Ships[ShipIndex];
	}

	////TODO Finish select

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (ShipIndex > 0)
			--ShipIndex;
		Selector.setPosition(window.getSize().x / 2 - 50.f, window.getSize().y / 2 + 60.f);
		SelectedShip = &Ships[ShipIndex];
	}

	window.draw(Title);
	window.draw(Selector);
}
