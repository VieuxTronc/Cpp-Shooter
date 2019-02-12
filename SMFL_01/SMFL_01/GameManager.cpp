#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "Projectile.h"
#include "DebugCustom.h"

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
	Background* pSplash = new Background("../data/splash.jpg", true, Background::FadeType::IN);
	splashList.push_back(pSplash);

	//Game
	Background* pBackground = new Background("../data/background.png", false, Background::FadeType::NONE);
	entitiesList.push_back(pBackground);

	Player::GetInstance()->InitPlayer(sf::Vector2f(0.0f, 0.0f), "../data/ship.png");
	entitiesList.push_back(Player::GetInstance());

	Enemy* pEnemy = new Enemy(sf::Vector2f(100.0f, 250.0f), "../data/ship.png");
	entitiesList.push_back(pEnemy);
	enemiesList.push_back(pEnemy);
	
	DebugCustom::Log("Entities Initiated.");
} 

void GameManager::UpdateEntities(float _dt)
{
	switch (mGameState)
	{
	case GameManager::BOOT_MENU:
		for (size_t i = 0; i < splashList.size(); i++)
		{
			splashList[i]->UpdateEntity(_dt);
			splashList[i]->SetEntityID(i);
		}
		break;
	case GameManager::GAME:
		CleanEntityList();
		for (size_t i = 0; i < entitiesList.size(); i++)
		{
			entitiesList[i]->UpdateEntity(_dt);
			entitiesList[i]->SetEntityID(i);
		}
		break;
	default:
		break;
	}
}

void GameManager::CleanEntityList()
{
	for (size_t i = 0; i < entitiesList.size(); i++)
	{
		if (entitiesList[i]->IsEntityAlive() == false)
		{
			Entity* entityToDelete = entitiesList[i];
			int idToDelete = entityToDelete->GetEntityID();

			DebugCustom::Log("Entity will be removed");

			delete entityToDelete;
			entitiesList.erase(entitiesList.begin() + idToDelete);
		}
	}
}

void GameManager::RemoveEntityFromList(int _id)
{
	delete entitiesList[_id];
	entitiesList.erase(entitiesList.begin() + _id);
	
	DebugCustom::Log("Entity has been removed ");
}

void GameManager::SpawnEntity(EntityType _type, sf::Vector2f _pos, unsigned int _number)
{
	for (size_t i = 0; i < _number; i++)
	{
		switch (_type)
		{
		case GameManager::ENEMY:

			break;
		case GameManager::PROJECTILE:
			Projectile* pProjectile = new Projectile(_pos, "../data/pokeball.png", Projectile::CollisionMode::ENEMY);
			entitiesList.push_back(pProjectile);
			DebugCustom::Log("Spawned a projectile");
			break;
		}
	}
}

void GameManager::SetGameState(GameState _state)
{
	mGameState = _state;
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

std::vector<Entity*> GameManager::GetCurrentEnemyList()
{
	if (GameManager::GAME)
	{
		return enemiesList; 
	}
}
