#pragma once

#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "InvaderArmy.h"
#include "Ship.h"

class Player
{
public:
	Player(const sf::Vector2f dim);
	~Player();

	void Draw(sf::RenderWindow& window);
	void Move(const Side side);
	void MoveBullets(InvaderArmy& army);
	void Fire();
	bool CheckEnemyBulletCollision(InvaderArmy& army);
	void SetPosition(float x, float y);
	void ResetShip();
	void CleanBullets();

	void SetShip(Ship* ship)
	{
		auto shipPosition = m_Ship.GetPosition();
		sf::FloatRect shipSize = m_Ship.GetSize();
		m_Ship = *ship;
		m_Ship.SetSize(shipSize);
		m_Ship.SetPosition(shipPosition.x, shipPosition.y);

	}

	inline sf::Vector2f GetPosition() const { return m_Ship.GetPosition(); }
	inline sf::RectangleShape& GetShape() { return m_Ship.GetShape(); }
	inline unsigned int GetMaxHP() const { return m_Ship.GetMaxHP(); }
	inline unsigned int GetHP() const { return m_Ship.HP; }
	inline float GetFireRate() const { return m_Ship.FireSpeed; }

private:
	Ship m_Ship;
	std::vector<Bullet> Bullets;

};

