#pragma once

#include "Player.h"

class PlayerController
{
protected:
	Player* mPlayer;
	Side MoveSide;
public:
	PlayerController(Player* p);

	void Move();
	void Fire(float& deltaTime);
};