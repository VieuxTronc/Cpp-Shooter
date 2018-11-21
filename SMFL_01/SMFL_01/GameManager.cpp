#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::InitEntities()
{
	Background* pBackground = new Background("../data/background.png");
	entitiesList.push_back(pBackground);
	pPlayer = new Player(sf::Vector2f(0.0f, 0.0f), "../data/ship.png");
	entitiesList.push_back(pPlayer);
	Enemy* pEnemy = new Enemy(sf::Vector2f(100.0f, 250.0f), "../data/ship.png");
	entitiesList.push_back(pEnemy);
}

void GameManager::ListenToInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		pPlayer->MoveEntity(sf::Vector2f(0.0f, -0.1f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pPlayer->MoveEntity(sf::Vector2f(0.0f, 0.1f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		pPlayer->MoveEntity(sf::Vector2f(-0.1f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pPlayer->MoveEntity(sf::Vector2f(0.1f, 0.0f));
	}
}

void GameManager::UpdateEntities()
{
	pPlayer->UpdateEntity();
}
