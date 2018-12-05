#include "pch.h"
#include "Entity.h"


Entity::Entity()
{
	printf("Entity created\n");
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

	sf::Vector2u mTexSize = mTexture.getSize();

	//mRect = sf::Rect(mPosition, mTexSize);

	printf("Entity created with texture and pos.\n");
}

void Entity::SetEntityRotation(float _angle)
{
	mAngle = _angle; 
	mSprite.setRotation(mAngle);
}
