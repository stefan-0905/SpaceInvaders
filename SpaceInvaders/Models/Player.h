#pragma once

#include "SFML/System/Vector2.hpp"

#include "old/Shapes/Bullet.h"
#include "InvaderArmy.h"
#include "../Constants.h"

class RenderWindow;
class Ship;

class Player
{
private:
	// Player's ship size
	sf::Vector2f Size;
	// Player's ship
	Ship* m_Ship;
	// Player's fired bullets
	std::vector<Bullet> Bullets;

	float HP;
public:
	Player(const sf::Vector2f dim);
	~Player();
	// Draw a player
	void Draw(sf::RenderWindow& window);
	// Fire a bullet
	void Fire();
	// Set player's position
	void SetPosition(float x, float y);
	// Reset player's HP and his ship killed state
	void ResetShip();
	// Delete all bullets
	void CleanBullets();
	// Check if player intersects with a shape
	bool Intersects(Shape* shape);
	// Decrease HP by specifies amount
	void DecreaseHP(float damage);
	// Set player's ship
	void SetShip(Ship* ship);
	// Get player's max hp
	unsigned int GetMaxHP() const;
	// Get player's hp
	inline float GetHP() const { return HP; }
	// Check if player is alive
	inline bool Alive() const { return HP > 0; }
	// Get fire rate of player's selected ship
	float GetFireRate() const;
	// Get player's size
	inline sf::Vector2f GetSize() const { return Size; };
	// Get player's ship
	inline Ship* GetShip() { return m_Ship; }
	// Get player's bullets
	inline std::vector<Bullet>* GetBullets() { return &Bullets; }

};

