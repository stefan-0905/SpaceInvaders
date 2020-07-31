#include "SFML/Graphics/RenderWindow.hpp"
#include "Shapes/Ship.h"


#include "Player.h"

#include "../Config.h"


Player::Player(const sf::Vector2f dim)
	: Size(dim.x, dim.y)
{
	m_Ship = new Ship(Size.x, Size.y);
	///Reserve memory locations for only 20 bullets 
	Bullets.reserve(BULLETS_ON_SCREEN);
}

Player::~Player()
{
}

void Player::SetShip(Ship* ship)
{
	*m_Ship = *ship;
	HP = static_cast<float>(ship->GetMaxHP());
	m_Ship->SetSize(Size.x, Size.y);
	m_Ship->SetPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y - m_Ship->GetGlobalBounds().height);
	m_Ship->SetCenteredOrigin();
}

unsigned int Player::GetMaxHP() const
{
	return m_Ship->GetMaxHP();
}

float Player::GetFireRate() const
{
	return m_Ship->GetFireSpeed();
}

//Draw player on screen
void Player::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < (int)Bullets.size(); i++)
	{
		Bullets[i].Draw(window);
	}

	m_Ship->Draw(window);
}

//Fire bullet 
void Player::Fire()
{
	// If there are move bullets then predicted, remove one from start.
	if (Bullets.size() == BULLETS_ON_SCREEN) Bullets.erase(Bullets.begin());

	// Set position to be on top of the player so that bullet doesn't spawn in the player center
	auto bulletPosition = m_Ship->GetPosition();
	bulletPosition.y -= m_Ship->GetGlobalBounds().height / 2;

	Bullets.emplace_back(Bullet(bulletPosition, m_Ship->GetDamage(), Bullet::Direction::Up));
}

void Player::SetPosition(float x, float y)
{
	m_Ship->SetPosition(x, y);
}

void Player::ResetShip()
{
	m_Ship->ResetKilled();
	HP = static_cast<float>(m_Ship->GetMaxHP());
}

void Player::CleanBullets()
{
	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		Bullets.erase(Bullets.begin() + i);
	}
}

bool Player::Intersects(Shape* shape)
{
	return m_Ship->Intersects(shape);
}

void Player::DecreaseHP(float damage)
{
	HP -= damage;
}

