#include "Player.h"

Player::Player(const sf::Vector2f dim)//, sf::Vector2u size)
{
	///Reserve memory locations for only 10 bullets 
	Bullets.reserve(10);

	///Init Player
	//Body.setTexture(texture);
	Body.setOrigin(sf::Vector2f(dim.x / 2, dim.y / 2));
	//Body.setPosition((float)size.x / 2, (float)size.y - Body.getGlobalBounds().height);

	HP = MaxHP;
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

	window.draw(Body);
}

//Move player Left - Right
void Player::Move(const Side side)
{
	switch (side)
	{
	case Side::Left:
		Body.move(-5.f, 0.0f);
		break;
	case Side::Right:
		Body.move(5.f, 0.0f);
		break;
	default:
		break;
	}

	if (Body.getPosition().x < 50)
		Body.setPosition(50, Body.getPosition().y);

	if (Body.getPosition().x > 974)
		Body.setPosition(974, Body.getPosition().y);
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

	Bullets.emplace_back(Bullet(Body.getPosition()));
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
	Body.setPosition(x, y);
}

void Player::SetTexture()
{
	DefenderTexture.loadFromFile("res/defender.jpg");
	Body.setTexture(DefenderTexture);
}
