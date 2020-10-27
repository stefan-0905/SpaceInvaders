#pragma once
#include "../../Models/ECS/ECS.h"
#include "../../Models/ECS/Manager.h"

#include "../UIBase.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class RenderWindow;
class SBanner;

class StartScreenUI : public UIBase
{
public:
	bool StartSelected;
private:
	Manager manager;

	SBanner* Banner;

public:
	StartScreenUI();
	~StartScreenUI();

	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;
};