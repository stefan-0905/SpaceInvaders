#include "PlayerAIController.h"

#include "../../Constants.h"

PlayerAIController::PlayerAIController(InvaderArmy* army)
	: Army(army), m_BulletAIController(Army->GetBullets())
{
	MoveSide = Side::Left;
}

void PlayerAIController::Tick(float deltaTime)
{
	auto enemyCount = Army->GetEnemyCount();
	/// Move all enemies
	for (unsigned int i = 0; i < enemyCount; i++)
	{
		auto offset = GetOffset();
		if (Army->GetEnemies()[i])
			Army->GetEnemies()[i]->Move(offset.x, offset.y);
	}

	/// Check if enemies are nearing the edge of the screen 
	if (Army->GetEnemies()[0] && Army->GetEnemies()[0]->GetPosition().x < 100)
		MoveSide = Side::Right;

	if (Army->GetEnemies()[enemyCount - 1] && Army->GetEnemies()[enemyCount - 1]->GetPosition().x > 924)
		MoveSide = Side::Left;

	Fire(deltaTime);
	m_BulletAIController.Tick(deltaTime);
}

sf::Vector2f PlayerAIController::GetOffset()
{
	float moveWidth = 1.f;
	switch (MoveSide)
	{
	case Side::Left:
		return(sf::Vector2f(-moveWidth, 0.f));
		break;
	default:
		return(sf::Vector2f(moveWidth, 0.f));
		break;
	}
}

void PlayerAIController::Fire(float deltaTime)
{
	static float totalTime = 0.f;
	totalTime += deltaTime;

	if (totalTime < 1.f) return;

	/// Get random column for the bullet
	int column = rand() % INVADERS_PER_ROW;

	/// Get the last row
	int row = (int)ceil(Army->GetEnemyCount() / INVADERS_PER_ROW) - 1;

	/// Determine the row of the invader that's not killed in the random column we got
	/// Row is getting substracted if invader is killed in that row
	/// Finally, finding the position of alive invader or not finding him and not firing the bullet
	do {
		auto enemy = Army->GetEnemies()[row * INVADERS_PER_ROW + column];
		if (enemy && !enemy->GetKilled())
		{
			sf::Vector2f invaderPosition = enemy->GetPosition();
			invaderPosition.y += 50;
			Army->GetBullets()->emplace_back(Bullet(invaderPosition, enemy->GetFireDamage(), Bullet::Direction::Down));
			totalTime -= 1.f;
			break;
		}
		else
		{
			--row;
		}
	} while (row >= 0);
}