#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include "pch.h"
#include "GameWindow.h"
#include "DebugCustom.h"
#include "Projectile.h"

Enemy::Enemy(sf::Vector2f _pos, std::string _spritePath)
{
	CreateEntity(_spritePath, sf::Vector2f(GameWindow::GetInstance()->GetWindowSizef().x - 350.0f, GameWindow::GetInstance()->GetWindowSizef().y / 2.0f), sf::Vector2f(1.0f, 1.0f));

	GameManager::GetInstance()->RegisterEnemy(this);
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}

void Enemy::UpdateEntity(float _dt)
{
	//Get bounds
	float maxY = GameWindow::GetInstance()->GetWindowSizef().y - mTexture.getSize().y;
	float maxX = GameWindow::GetInstance()->GetWindowSizef().x - mTexture.getSize().x;

	//Apply calculus to position
	mPosition.x += (mSpeed / 2.0f * _dt) * mVelocity.x;
	mPosition.y += (mSpeed * _dt) * mVelocity.y;

	//Check Bounds
	if (mPosition.y >= maxY)
	{
		mVelocity.y = -1.0f;
	}
	if (mPosition.y <= 0.0f)
	{
		mVelocity.y = 1.0f;
	}
	if (mPosition.x <= 0.0f)
	{
		mVelocity.x = 1.0f;
	}
	if (mPosition.x >= maxX)
	{
		mVelocity.x = -1.0f;
	}

	mSprite.setPosition(mPosition);

	mRect = sf::FloatRect(mPosition, mSize);

	GetDebugDrawable(); 

	CheckIfEntityIsAlive(); 
}

void Enemy::UpdateDebugDrawable()
{
	mDebugRectShape = sf::RectangleShape(mSize);
	mDebugRectShape.setPosition(mPosition);
	mDebugRectShape.setFillColor(sf::Color::Transparent);
	mDebugRectShape.setOutlineColor(sf::Color::Red);
	mDebugRectShape.setOutlineThickness(2.5f);
}

void Enemy::ApplyDamage(Entity * _projectile)
{
	mLifePoints -= _projectile->GetProjectileDamage(); 
}

void Enemy::CheckIfEntityIsAlive()
{
	if (mLifePoints <= 0)
	{
		mIsAlive = false; 
	}
}
