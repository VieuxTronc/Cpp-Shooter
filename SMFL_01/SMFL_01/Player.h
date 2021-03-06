#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	static Player* GetInstance(); 

	void InitPlayer(sf::Vector2f _pos, std::string _spritePath);

	void UpdateEntity(float _dt);

	void CheckPlayerBounds(sf::Vector2f _futurePos, sf::Vector2f _velocity);

	void MoveEntity(sf::Vector2f _velocity, float _dt);

	void Fire(float _dt);

private:
	static Player* s_pInstance; 
	Player();
	~Player();

	float mSpeed;
	float mFireRate;
	float mFireTimer;
	float mLifePoints; 
};

