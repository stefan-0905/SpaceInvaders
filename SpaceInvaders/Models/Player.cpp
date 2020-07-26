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

//Draw player on screen
void Player::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < (int)Bullets.size(); i++)
	{
		Bullets[i].Draw(window);
	}

	m_Ship->Draw(window);
}

//Move player Left - Right
void Player::Move(const Side side)
{
	switch (side)
	{
	case Side::Left:
		m_Ship->Move(-5.f, 0.0f);
		break;
	case Side::Right:
		m_Ship->Move(5.f, 0.0f);
		break;
	default:
		break;
	}

	if (m_Ship->GetPosition().x < 50)
		m_Ship->SetPosition(50, m_Ship->GetPosition().y);

	if (m_Ship->GetPosition().x > 974)
		m_Ship->SetPosition(974, m_Ship->GetPosition().y);
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
		for (unsigned int k = 0; k < army.GetEnemyCount(); k++)
		{
			if (!army.GetEnemies()[k]->GetKilled() && Bullets[i].Intersects(((Shape*)army.GetEnemies()[k])))
			{
				Bullets.erase(Bullets.begin() + i);
				army.Injure(k, m_Ship->GetDamage());
				break;
			}
		}
	}
}

//Fire bullet 
void Player::Fire()
{
	// If there are move bullets then predicted, remove one from start.
	if (Bullets.size() == BULLETS_ON_SCREEN) Bullets.erase(Bullets.begin());

	// Set position to be on top of the player so that bullet doesn't spawn in the player center
	auto bulletPosition = m_Ship->GetPosition();
	bulletPosition.y -= m_Ship->GetGlobalBounds().height / 2;

	Bullets.emplace_back(Bullet(bulletPosition, m_Ship->GetDamage()));
}

bool Player::CheckEnemyBulletCollision(InvaderArmy* army)
{
	std::vector<Bullet>* EnemyBullets = army->GetBullets();
	for (unsigned int i = 0; i < EnemyBullets->size(); i++)
	{
		auto shipShape = dynamic_cast<Shape*>(m_Ship);
		if (shipShape && EnemyBullets->at(i).Intersects(shipShape))
		{
			HP -= EnemyBullets->at(i).GetDamage();
			army->DestroyBullet(i);
		}
	}

	return HP > 0;
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