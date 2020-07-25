#pragma once

#include "Invaders/Invader.h"
#include "InvaderArmy.h"

class Level
{
protected:
	// Army on the current level
	InvaderArmy* Army;
	unsigned int Current;

public:
	Level(InvaderArmy* army);
	~Level();
	unsigned int GetEnemyCountBasedOnCurrentLevel() const;
	void Generate();

	void StartNewGame();
	void Next();

	inline unsigned int GetCurrentLevel() const { return Current; }
	inline bool Completed() const { return Army->EnemiesDestroyed(); }
};