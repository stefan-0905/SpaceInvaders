#pragma once
#include "Models/ECS/Manager.h"
#include "Models/ECS/AInvader.h"
#include "Constants.h"

class Spawner
{
public:
	static void Spawn(size_t n, Manager* manager)
	{
		int offset = WINDOW_SIZE_X - 100 - INVADERS_PER_ROW * 40;
		auto startX = 30.f;
		auto startY = 50.f;

		int Row = 0;

		for (size_t i = 0; i < n; i++)
		{
			if (i % INVADERS_PER_ROW == 0)
			{
				Row++;
				startX = 30.f;
			}

			startX += 40.f;

			manager->AddActor<AInvader>(startX, startY + 50.f * Row, (float)offset);
		}

	}
};
