#pragma once

#include "Entity.h"

class Projectile : public Entity
{
public:
	enum CollisionMode {PLAYER, ENEMY};

	Projectile(sf::Vector2f _pos, std::string _spritePath, CollisionMode _colMode);
	~Projectile();

	void LaunchProjectile(sf::Vector2f _volicity);
	void MoveEntity(float _dt);
	void CheckEntityCollision();
	void UpdateEntity(float _dt);


private: 
	CollisionMode mCollisionMode;
	float mSpeed = 350.0f;
};

