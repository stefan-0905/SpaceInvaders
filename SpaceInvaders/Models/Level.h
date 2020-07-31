#pragma once

class InvaderArmy;

class Level
{
protected:
	// Army on the current level
	InvaderArmy* Army;
	// Current level
	unsigned int Current;

public:
	// Maximum level
	static const unsigned int MaxLevel = 3;
	Level(InvaderArmy* army);
	~Level();
	// Get number of enemies that should be based on a current level
	unsigned int GetEnemyCountBasedOnCurrentLevel() const;
	// Generate enemies for the current level
	void Generate();
	// Set first level and generate enemies for it
	void StartNewGame();
	// Level up and generate enemies
	void Next();
	// Get current level
	inline unsigned int GetCurrentLevel() const { return Current; }
	// Check if level is completed. It's completed if all enemies are destroyed.
	bool Completed() const;
};