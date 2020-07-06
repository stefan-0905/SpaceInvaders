#pragma once

#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "InvaderArmy.h"

class Player
{
public:
	Player(const sf::Vector2f dim, const sf::Texture& texture, sf::Vector2u size);
	~Player();

	void Draw(sf::RenderWindow& window);
	void Move(const Side side);
	void MoveBullets(InvaderArmy& army);
	void Fire();
	bool CheckEnemyBulletCollision(InvaderArmy& army);

	sf::Vector2f GetPosition() const { return Body.getPosition(); }
	sf::Sprite& GetShape() { return Body; }

public:
	const unsigned int MaxHP = 3;
	unsigned int HP;
private:
	sf::Sprite Body;
	std::vector<Bullet> Bullets;

};

