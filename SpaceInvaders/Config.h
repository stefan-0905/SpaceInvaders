#pragma once
#include <SFML\Graphics.hpp>

class Config
{
public:
	sf::Font Font;
	sf::Texture SlingerTexture;
	sf::Texture BazookerTexture;
	sf::Texture Invader1;
	sf::Texture Invader2;
	sf::Texture Invader3;
public:
	Config()
	{
		Font.loadFromFile("res/fonts/micross.ttf");
		SlingerTexture.loadFromFile("res/Slinger.png");
		BazookerTexture.loadFromFile("res/Bazooker.png");
		Invader1.loadFromFile("res/invader1.png");
		Invader2.loadFromFile("res/invader2.png");
		Invader3.loadFromFile("res/invader3.png");
	}

	static Config& GetInstance()
	{
		static Config instance = Config();
		return instance;
	}

	static sf::Font& GetFont()
	{
		return GetInstance().Font;
	}

	static sf::Texture& GetSlingerTexture()
	{
		return GetInstance().SlingerTexture;
	}

	static sf::Texture& GetBazookerTexture()
	{
		return GetInstance().BazookerTexture;
	}

	static sf::Texture& GetInvader1()
	{
		return GetInstance().Invader1;
	}

	static sf::Texture& GetInvader2()
	{
		return GetInstance().Invader2;
	}

	static sf::Texture& GetInvader3()
	{
		return GetInstance().Invader3;
	}
};