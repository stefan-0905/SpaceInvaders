#pragma once
#include "../UIBase.h"

#include "../../Models/ECS/Manager.h"

class RenderWindow;
class SStaticText; 

class OverUI : public UIBase
{
public:
	bool Selected;

private:
	Manager manager;

	SStaticText* ResultText;

	bool Won;

public:
	OverUI();
	void EndWith(bool won); 
	void Tick(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

};

