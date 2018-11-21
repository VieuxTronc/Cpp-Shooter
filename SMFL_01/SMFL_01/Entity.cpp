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

	UpdateEntity();

	printf("Entity created with texture and pos.\n");
}

void Entity::MoveEntity(sf::Vector2f _amount) 
{
	mPosition.x = (mSpeed > 0.0f) ? mPosition.x + (_amount.x * mSpeed) : mPosition.x + _amount.x;
	mPosition.y = (mSpeed > 0.0f) ? mPosition.y + (_amount.y * mSpeed) : mPosition.y + _amount.y;
}

void Entity::UpdateEntity()
{
	mSprite.setPosition(mPosition);
}


