#include "pch.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "GameWindow.h"

Player* Player::s_pInstance = nullptr;

Player::Player()
{

}

Player::~Player()
{
}

Player* Player::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Player(); 
	}

	return s_pInstance;
}

void Player::InitPlayer(sf::Vector2f _pos, std::string _spritePath)
{
	_pos.x = (GameWindow::GetInstance()->GetWindowSizef().x / 4) - mTexture.getSize().x;
	_pos.y = (GameWindow::GetInstance()->GetWindowSizef().y / 2) - mTexture.getSize().y;

	CreateEntity(_spritePath, _pos, sf::Vector2f(1.0f, 1.0f));
}

void Player::UpdateEntity(float _dt)
{
	UpdateDebugDrawable();
}

void Player::CheckPlayerBounds(sf::Vector2f _futurePos, sf::Vector2f _velocity)
{
	float maxY = GameWindow::GetInstance()->GetWindowSizef().y - mTexture.getSize().y;
	float maxX = GameWindow::GetInstance()->GetWindowSizef().x - mTexture.getSize().x;

	if (_futurePos.y > maxY && _velocity.y > 0) {mVelocity.y = 0.0f;}
	if (_futurePos.y < 0.0f && _velocity.y < 0) {mVelocity.y = 0.0f;}
	if (_futurePos.x < 0.0f && _velocity.x < 0) {mVelocity.x = 0.0f;}
	if (_futurePos.x > maxX && _velocity.x > 0) {mVelocity.x = 0.0f;}
}

void Player::MoveEntity(sf::Vector2f _inputVelocity, float _dt)
{
	mVelocity.x = _inputVelocity.x;
	mVelocity.y = _inputVelocity.y;

	CheckPlayerBounds(mPosition, mVelocity);

	mPosition.x += (mSpeed * _dt) * mVelocity.x;
	mPosition.y += (mSpeed * _dt) * mVelocity.y;

	mSprite.setPosition(mPosition);

	mRect = sf::FloatRect(mPosition, mSize);
}

void Player::Fire(float _dt)
{
	if (mFireTimer >= mFireRate)
	{
		GameManager::GetInstance()->SpawnEntity(GameManager::EntityType::PROJECTILE, sf::Vector2f(mPosition.x + mSize.x, mPosition.y + mSize.y / 2.5f), 1);
		mFireTimer = 0.0f;
	}

	mFireTimer += _dt;
}

