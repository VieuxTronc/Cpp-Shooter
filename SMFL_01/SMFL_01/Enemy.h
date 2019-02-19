#pragma once

#include "Entity.h"
#include "Projectile.h"

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(sf::Vector2f _pos, std::string _spritePath);
	~Enemy();

	void UpdateEntity(float _dt);
	void UpdateDebugDrawable();
	void ApplyDamage(Entity* _projectile); 
	void CheckIfEntityIsAlive(); 

private: 
	float mSpeed = 250.0f;
};

