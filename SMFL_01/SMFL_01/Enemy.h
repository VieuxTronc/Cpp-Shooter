#pragma once

#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(sf::Vector2f _pos, std::string _spritePath);
	~Enemy();
};

