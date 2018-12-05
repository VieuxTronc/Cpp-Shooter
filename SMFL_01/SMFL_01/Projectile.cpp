#include "pch.h"
#include "Projectile.h"
#include "Player.h"
#include "GameWindow.h"

Projectile::Projectile(sf::Vector2f _pos, std::string _spritePath, CollisionMode _colMode)
{
	CreateEntity(_pos, _spritePath);
	mSprite.setColor(sf::Color(255, 255, 255, 0));
	mCollisionMode = _colMode;
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
	}
}

void Projectile::CheckEntityCollision()
{
	switch (mCollisionMode)
	{
	case Projectile::PLAYER:

		break;
	case Projectile::ENEMY:
		//if(IntersectRect())
		if (mPosition.x <= Player::GetInstance()->GetEntityPosition().x)
		{
			printf("coll with player X");
		}
		break;
	default:
		printf("No Collision mode set for this projectile.");
		break;
	}

	//TODO Remove missile correctly 
	if (mPosition.x >= GameWindow::GetInstance()->GetWindowSize().x)
	{
		//GameManager::GetInstance()->GetCurrentEntityList().era();
	}
	if (mPosition.y >= GameWindow::GetInstance()->GetWindowSize().y)
	{
		printf("OOB");
	}
}

void Projectile::UpdateEntity(float _dt)
{
	MoveEntity(_dt);
	CheckEntityCollision();
}
