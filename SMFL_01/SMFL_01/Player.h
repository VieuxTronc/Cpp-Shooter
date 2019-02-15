#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	static Player* GetInstance(); 
	void InitPlayer(sf::Vector2f _pos, std::string _spritePath);
	void UpdateEntity(float _dt);
	void UpdateDebugDrawable();
	void CheckPlayerBounds(sf::Vector2f _futurePos, sf::Vector2f _velocity);
	void MoveEntity(sf::Vector2f _velocity, float _dt);
	void Fire(float _dt);

private:
	static Player* s_pInstance; 
	Player();
	~Player();
	float mSpeed = 250.0f;
	float mFireRate = 0.25f;
	float mFireTimer = mFireRate;
};

