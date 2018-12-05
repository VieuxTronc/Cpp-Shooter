#include "pch.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include "GameWindow.h"

Enemy::Enemy()
{

}

Enemy::Enemy(sf::Vector2f _pos, std::string _spritePath)
{
	CreateEntity(sf::Vector2f(GameWindow::GetInstance()->GetWindowSizef().x - 350.0f, GameWindow::GetInstance()->GetWindowSizef().y / 2.0f), _spritePath);
	mVelocity = sf::Vector2f(1.0f, 1.0f);
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

	//std::cout << std::to_string(mPosition.y).c_str() << endl;

	mSprite.setPosition(mPosition);

}
