#include "pch.h"
#include "Entity.h"
#include "DebugCustom.h"
#include "GameManager.h"

Entity::Entity()
{
	DebugCustom::Log("Entity Constructor called.");
}

Entity::~Entity()
{
}

void Entity::CreateEntity(std::string _spritePath, sf::Vector2f _pos, sf::Vector2f _velocity)
{
	mTexture.loadFromFile(_spritePath);
	mSprite.setTexture(mTexture);

	mPosition = _pos;
	mSprite.setPosition(mPosition);

	mVelocity = _velocity;

	mSize = sf::Vector2f(static_cast<float>(mTexture.getSize().x), static_cast<float>(mTexture.getSize().y));

	mRect = sf::FloatRect(mPosition, mSize);

	//Init debug rectangle shape
	mDebugRectShape = sf::RectangleShape(mSize);
	mDebugRectShape.setFillColor(sf::Color::Transparent);
	mDebugRectShape.setOutlineColor(sf::Color::Red);
	mDebugRectShape.setOutlineThickness(2.5f);

	//Register entity into game manager
	GameManager::GetInstance()->RegisterEntity(this);

	DebugCustom::Log("Entity created with texture and pos.");
}

void Entity::SetEntityRotation(float _angle)
{
	mAngle = _angle; 
	mSprite.setRotation(mAngle);
}

void Entity::UpdateDebugDrawable()
{
	mDebugRectShape.setPosition(mPosition);
}
