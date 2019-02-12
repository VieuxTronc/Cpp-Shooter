#include "pch.h"
#include "Projectile.h"
#include "Player.h"
#include "GameWindow.h"
#include "GameManager.h"
#include "DebugCustom.h"

Projectile::Projectile(sf::Vector2f _pos, std::string _spritePath, CollisionMode _colMode)
{
	CreateEntity(_pos, _spritePath);
	mSprite.setColor(sf::Color(255, 255, 255, 0));
	mCollisionMode = _colMode;
	mSprite.setScale(sf::Vector2f(0.5f, 0.5f));
	LaunchProjectile(sf::Vector2f(1.0f, 0.0f));
}

Projectile::~Projectile()
{
}

void Projectile::LaunchProjectile(sf::Vector2f _volicity)
{
	mSprite.setColor(sf::Color(255, 255, 255, 255));
	mVelocity = _volicity;
	mIsAlive = true;
}

void Projectile::MoveEntity(float _dt)
{
	if (IsEntityAlive())
	{
		mPosition.x += (mSpeed * _dt) * mVelocity.x;
		mPosition.y += (mSpeed * _dt) * mVelocity.y;

		mSprite.setPosition(mPosition);

		mRect = sf::FloatRect(mPosition, mSize);
	}
}

void Projectile::CheckEntityCollision()
{
	std::vector<Entity*> enemyList = GameManager::GetInstance()->GetCurrentEnemyList();

	switch (mCollisionMode)
	{
	case Projectile::PLAYER:

		break;
	case Projectile::ENEMY:
		for (size_t i = 0; i < enemyList.size(); i++)
		{
			sf::FloatRect tempEnemyRect = enemyList[i]->GetEntityRect();
			
			if (mRect.intersects(tempEnemyRect) == true)
			{
				DebugCustom::Log("Projectile Intersecting");
				enemyList[i]->DestroyEntity();
			}
		}
		break;
	default:
		DebugCustom::Warning("No collision mode set for this projectile !");
		break;
	}

	if (mPosition.x >= GameWindow::GetInstance()->GetWindowSize().x)
	{
		mIsAlive = false; 
	}
	if (mPosition.y >= GameWindow::GetInstance()->GetWindowSize().y)
	{
		mIsAlive = false;
	}
}

void Projectile::UpdateEntity(float _dt)
{
	MoveEntity(_dt);
	CheckEntityCollision();
}
