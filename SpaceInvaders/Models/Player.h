#pragma once

#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "InvaderArmy.h"
#include "Ship.h"
#include "../Constants.h"

class Player
{
public:
	Player(const sf::Vector2f dim);
	~Player();

	void Draw(sf::RenderWindow& window);
	void Move(const Side side);
	void MoveBullets(InvaderArmy& army);
	void Fire();
	bool CheckEnemyBulletCollision(InvaderArmy* army);
	void SetPosition(float x, float y);
	void ResetShip();
	void CleanBullets();

	void SetShip(Ship* ship);

	inline unsigned int GetMaxHP() const { return m_Ship->GetMaxHP(); }
	inline float GetHP() const { return HP; }
	inline float GetFireRate() const { return m_Ship->GetFireSpeed(); }
	inline sf::Vector2f GetSize() const { return Size; };
	inline Ship* GetShip() { return m_Ship; }
private:
	sf::Vector2f Size;
	Ship* m_Ship;
	std::vector<Bullet> Bullets;

	float HP;

};

