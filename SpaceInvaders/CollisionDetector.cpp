#include "CollisionDetector.h"

CollisionDetector::CollisionDetector(Player* mPlayer, InvaderArmy* mArmy)
{
	m_Player = mPlayer;
	m_Army = mArmy;
}

void CollisionDetector::Tick(float deltaTime)
{
	CheckEnemyBulletCollision();
	CheckPlayerBulletCollision();
}

void CollisionDetector::CheckEnemyBulletCollision()
{
	std::vector<Bullet>* EnemyBullets = m_Army->GetBullets();
	for (unsigned int i = 0; i < EnemyBullets->size(); i++)
	{

		if (m_Player->Intersects(&EnemyBullets->at(i)))
		{
			m_Player->DecreaseHP(EnemyBullets->at(i).GetDamage());
			m_Army->DestroyBullet(i);
		}
	}
}

void CollisionDetector::CheckPlayerBulletCollision()
{
	auto playerBullets = m_Player->GetBullets();
	for (unsigned int i = 0; i < playerBullets->size(); i++)
	{
		/// Check if bulllet hit something
		for (unsigned int k = 0; k < m_Army->GetEnemyCount(); k++)
		{
			auto enemy = m_Army->GetEnemies()[k];
			if (!enemy->GetKilled() && playerBullets->at(i).Intersects(enemy))
			{
				playerBullets->erase(playerBullets->begin() + i);
				m_Army->Injure(k, m_Player->GetShip()->GetDamage());
				break;
			}
		}
	}
}
