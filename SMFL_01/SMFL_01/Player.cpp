#include "pch.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "GameWindow.h"

Player::Player()
{

}

Player::Player(sf::Vector2f _pos, std::string _spritePath)
{
	CreateEntity(_pos, _spritePath);
}

Player::~Player()
{
}