#pragma once

#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "InvaderArmy.h"

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
	void SetTexture();

	sf::Vector2f GetPosition() const { return Body.getPosition(); }
	sf::Sprite& GetShape() { return Body; }

public:
	const unsigned int MaxHP = 3;
	unsigned int HP;
private:
	sf::Sprite Body;
	sf::Texture DefenderTexture;
	std::vector<Bullet> Bullets;

};

