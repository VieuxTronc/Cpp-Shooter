#include "pch.h"
#include "Entity.h"
#include "DebugCustom.h"

Entity::Entity()
{
	DebugCustom::Log("Entity Constructor called.");
}

Entity::~Entity()
{
}

void Entity::CreateEntity(sf::Vector2f _pos, std::string _spritePath)
{
	mTexture.loadFromFile(_spritePath);
	mSprite.setTexture(mTexture);

	mPosition = _pos;
	mSprite.setPosition(mPosition);

	mVelocity = sf::Vector2f(0.0f, 0.0f);

	mSize = sf::Vector2f(static_cast<float>(mTexture.getSize().x), static_cast<float>(mTexture.getSize().y));

	mRect = sf::FloatRect(mPosition, mSize);

	DebugCustom::Log("Entity created with texture and pos.");
}

void Entity::SetEntityRotation(float _angle)
{
	mAngle = _angle; 
	mSprite.setRotation(mAngle);
}
