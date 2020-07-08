#pragma once
#include <SFML\Graphics.hpp>

class Config
{
public:
	sf::Font Font;
	sf::Texture SlingerTexture;
	sf::Texture BazookerTexture;

public:
	Config()
	{
		Font.loadFromFile("fonts/micross.ttf");
		SlingerTexture.loadFromFile("res/Slinger.png");
		BazookerTexture.loadFromFile("res/Bazooker.png");
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
};