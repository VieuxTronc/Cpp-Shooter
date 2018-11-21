#include "pch.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>

Enemy::Enemy()
{

}

Enemy::Enemy(sf::Vector2f _pos, std::string _spritePath)
{
	CreateEntity(_pos, _spritePath);
}

Enemy::~Enemy()
{
}
