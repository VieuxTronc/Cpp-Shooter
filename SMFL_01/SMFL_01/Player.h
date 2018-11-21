#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	Player(sf::Vector2f _pos, std::string _spritePath);
	~Player();
};

