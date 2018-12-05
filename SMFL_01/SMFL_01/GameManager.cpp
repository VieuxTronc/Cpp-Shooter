#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "Projectile.h"

GameManager* GameManager::s_pInstance = nullptr;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

GameManager* GameManager::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new GameManager();
	}

	return s_pInstance;
}

void GameManager::InitEntities()
{
	//Splash Screen
	Background* pSplash = new Background("../data/splash.jpg");
	splashList.push_back(pSplash);

	//Game
	Background* pBackground = new Background("../data/background.png");
	entitiesList.push_back(pBackground);

	Player::GetInstance()->InitPlayer(sf::Vector2f(0.0f, 0.0f), "../data/ship.png");
	entitiesList.push_back(Player::GetInstance());

	Enemy* pEnemy = new Enemy(sf::Vector2f(100.0f, 250.0f), "../data/ship.png");
	entitiesList.push_back(pEnemy);

	printf("Entities Initiated.\n");
} 

void GameManager::UpdateEntities(float _dt)
{
	switch (mGameState)
	{
	case GameManager::BOOT_MENU:
		for (size_t i = 0; i < splashList.size(); i++)
		{
			splashList[i]->UpdateEntity(_dt);
		}
		break;
	case GameManager::GAME:
		for (size_t i = 0; i < entitiesList.size(); i++)
		{
			entitiesList[i]->UpdateEntity(_dt);
		}
		break;
	default:
		break;
	}
}

void GameManager::CleanList(std::vector<Entity*> _list)
{
	for (size_t i = 0; i < _list.size(); i++)
	{
		delete _list[i]; 
	}
	std::cout << "Cleaning done in Game Manager." << endl;
}

void GameManager::RemoveEntityFromList(Entity _entity)
{

}

void GameManager::SpawnEntity(EntityType _type, sf::Vector2f _pos, unsigned int _number)
{
	if (_type == EntityType::PLAYER)
	{
		//respawn Player
	}
	for (size_t i = 0; i < _number; i++)
	{
		switch (_type)
		{
		case GameManager::ENEMY:

			break;
		case GameManager::PROJECTILE:
			Projectile* pProjectile = new Projectile(_pos, "../data/pokeball.png", Projectile::CollisionMode::ENEMY);
			entitiesList.push_back(pProjectile);
			printf("Spawned a projectile");
			break;
		}
	}
}

void GameManager::SetGameState(GameState _state)
{
	mGameState = _state;
	//std::cout << "Current Game state is : " + std::to_string(_state) << endl;
}

std::vector<Entity*> GameManager::GetCurrentEntityList()
{
	switch (mGameState)
	{
	case GameManager::BOOT_MENU:
		return splashList; 
		break;
	case GameManager::GAME:
		return entitiesList;
		break;
	default:
		break;
	}
}