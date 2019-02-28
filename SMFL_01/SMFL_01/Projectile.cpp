#include "pch.h"
#include "Projectile.h"
#include "Player.h"
#include "GameWindow.h"
#include "GameManager.h"
#include "DebugCustom.h"
#include "HUDManager.h"

Projectile::Projectile(sf::Vector2f _pos, std::string _spritePath, CollisionMode _colMode)
{
	CreateEntity(_spritePath, _pos);
	mSprite.setColor(sf::Color(255, 255, 255, 0));
	mCollisionMode = _colMode;
	mSprite.setScale(sf::Vector2f(0.5f, 0.5f));
	mSize = sf::Vector2f(mSize.x * mSprite.getScale().x, mSize.y * mSprite.getScale().y);
	mDebugRectShape.setSize(mSize);
	LaunchProjectile(sf::Vector2f(1.0f, 0.0f));
}

Projectile::~Projectile()
{
}

void Projectile::LaunchProjectile(sf::Vector2f _velocity)
{
	mSprite.setColor(sf::Color(255, 255, 255, 255));
	mVelocity = _velocity;
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

		UpdateDebugDrawable();
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
		if(enemyList.size() <= 0) //NEED COLLISION FLAG SYSTEM IN ENTITY
		{
			return;
		}
		for (size_t i = 0; i < enemyList.size(); i++)
		{
			sf::FloatRect tempEnemyRect = enemyList[i]->GetEntityRect();
			
			if (mRect.intersects(tempEnemyRect) == true)
			{
				//Update points each  time we touch 
				//HUDManager::GetInstance()->GetPointsCounter()->UpdateText()
				enemyList[i]->ApplyDamage(this);
				mIsAlive = false;
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
