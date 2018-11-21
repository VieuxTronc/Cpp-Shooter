#pragma once

#include "pch.h"
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	void CreateEntity(sf::Vector2f _pos, std::string _spritePath); 

	void SetEntityPosition(sf::Vector2f _pos) { mPosition = _pos; }
	sf::Vector2f GetEntityPosition() { return mPosition; }

	sf::Sprite GetSprite() { return mSprite; }

	void SetEntityRotation(float _angle) { mAngle = _angle; }
	float GetEntityRotation() { return mAngle; }

	void MoveEntity(sf::Vector2f _amount);
	void SetEntitySpeed(float _newSpeed) { mSpeed = _newSpeed; }

	virtual void UpdateEntity();
	/*
	virtual bool IsEntityAlive() { return mIsAlive; }
	virtual void DestroyEntity();*/

protected:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::Vector2f mPosition;
	float mAngle;
	bool mIsAlive;
	float mSpeed = 0.4f; 
};

