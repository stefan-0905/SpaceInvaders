#include "Player.h"

#include "Config.h"

Player::Player(const sf::Vector2f dim)//, sf::Vector2u size)
	: m_Ship(dim.x, dim.y)
{
	///Reserve memory locations for only 10 bullets 
	Bullets.reserve(20);

	HP = m_Ship.GetMaxHP();
}

Player::~Player()
{
}

//Draw player on screen
void Player::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < (int)Bullets.size(); i++)
	{
		Bullets[i].Draw(window);
	}

	window.draw(m_Ship.GetShape());
}

//Move player Left - Right
void Player::Move(const Side side)
{
	switch (side)
	{
	case Side::Left:
		m_Ship.Move(-5.f, 0.0f);
		break;
	case Side::Right:
		m_Ship.Move(5.f, 0.0f);
		break;
	default:
		break;
	}

	if (m_Ship.GetPosition().x < 50)
		m_Ship.SetPosition(50, m_Ship.GetPosition().y);

	if (m_Ship.GetPosition().x > 974)
		m_Ship.SetPosition(974, m_Ship.GetPosition().y);
}

void Player::MoveBullets(InvaderArmy& army)
{
	for (unsigned int i = 0; i < Bullets.size(); i++)
	{
		Bullets[i].Move(1);

		/// Remove if bullet misses everything and exits screen
		if (Bullets[i].GetPosition().y <= 0)
		{
			Bullets.erase(Bullets.begin() + i);
			continue;
		}

		//TODO Maybe start counting from middle of height

		/// Check if bulllet hit something
		for (int k = 0; k < army.GetCount(); k++)
		{
			if (!army.GetEnemies()[k].Killed && Bullets[i].Intersects((army.GetEnemies()[k]).GetShape()))
			{
				Bullets.erase(Bullets.begin() + i);
				army.Kill(k);
				break;
			}
		}
	}
}

//Fire bullet 
void Player::Fire()
{
	///Allow only 10 bullets on the screen
	if (Bullets.size() == 10) Bullets.erase(Bullets.begin());

	Bullets.emplace_back(Bullet(m_Ship.GetPosition()));
}

bool Player::CheckEnemyBulletCollision(InvaderArmy& army)
{
	std::vector<Bullet>& EnemyBullets = *army.GetBullets();
	for (unsigned int i = 0; i < EnemyBullets.size(); i++)
	{
		if (EnemyBullets[i].Intersects(GetShape()))
		{
			army.DestroyBullet(i);
			HP--;
		}
	}

	return HP;
}

void Player::SetPosition(float x, float y)
{
	m_Ship.SetPosition(x, y);
}