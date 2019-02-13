#pragma once

#include "pch.h"
#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Rect.hpp"

class Entity
{
public:
	Entity();
	~Entity();

	void CreateEntity(sf::Vector2f _pos, std::string _spritePath); 
	virtual void DestroyEntity() {};

	void SetEntityID(int _id) { mEntityID = _id; }
	int GetEntityID() { return mEntityID; }

	void SetEntityPosition(sf::Vector2f _pos) { mPosition = _pos; }
	sf::Vector2f GetEntityPosition() { return mPosition; }

	virtual sf::Drawable* GetDrawable() { return &mSprite; }

	void SetEntityRotation(float _angle);
	float GetEntityRotation() { return mAngle; }

	virtual void MoveEntity(sf::Vector2f _velocity, float _dt) {};
	virtual void MoveEntity(float _dt) {};

	virtual void SetEntitySpeed(float _newSpeed) { mSpeed = _newSpeed; }
	float GetEntitySpeed() { return mSpeed; }

	virtual void UpdateEntity(float _dt) {};
	virtual void UpdateEntity() {};
	
	virtual bool IsEntityAlive() { return mIsAlive; }

	void SetEntityLifeTime(float _newTime) { mLifeTime = _newTime; }
	float GetEntityLifeTime() { return mLifeTime; }

	virtual void Fire() {};
	virtual void CheckEntityCollision() {};

	sf::FloatRect GetEntityRect() { return mRect; }

	void SetEntityTag(string _tag) { mTag = _tag; }
	string GetEntityTag() { return mTag; }

protected:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	sf::Vector2f mSpawnPosition;
	sf::FloatRect mRect;
	sf::Vector2f mSize;
	string mTag; 
	float mAngle;
	bool mIsAlive;
	float mSpeed = 135.0f; 
	float mLifeTime;
	int mEntityID; 
};

