#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "Projectile.h"
#include "DebugCustom.h"
#include "UIText.h"
#include "BootMenuManager.h"
#include "SplashScreenManager.h"

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

void GameManager::InitGame()
{
	SplashScreenManager::GetInstance()->InitSplashScreen();
}

void GameManager::InitLevel() //Will need int as a parameter to init the proper level. 
{
	Background* pBackground = new Background("../data/background.png", false, Background::FadeType::NONE);

	Player::GetInstance()->InitPlayer(sf::Vector2f(0.0f, 0.0f), "../data/ship.png");

	Enemy* pEnemy = new Enemy(sf::Vector2f(100.0f, 250.0f), "../data/ship.png");
}


void GameManager::UpdateEntities(float _dt)
{
	CleanCurrentEntityList(); 

	for (size_t i = 0; i < mCurrentEntityList.size(); i++)
	{
		mCurrentEntityList[i]->UpdateEntity(_dt);
		mCurrentEntityList[i]->SetEntityID(i);
	}
}

void GameManager::CleanCurrentEntityList()
{
	for (size_t i = 0; i < mCurrentEntityList.size(); i++)
	{
		if (mCurrentEntityList[i]->IsEntityAlive() == false)
		{
			Entity* entityToDelete = mCurrentEntityList[i];
			int idToDelete = entityToDelete->GetEntityID();
			
			DebugCustom::Log("Entity will be removed");

			delete entityToDelete;
			mCurrentEntityList.erase(mCurrentEntityList.begin() + idToDelete);
		}
	}
}

void GameManager::FlushCurrentEntities()
{
	for (size_t i = 0; i < mCurrentEntityList.size(); i++)
	{
		delete mCurrentEntityList[i];
		mCurrentEntityList.erase(mCurrentEntityList.begin() + i);
	}
}

//void GameManager::RemoveEntityFromList(int _id)
//{
//	delete entitiesList[_id];
//	entitiesList.erase(entitiesList.begin() + _id);
//	
//	DebugCustom::Log("Entity has been removed ");
//}

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
			DebugCustom::Log("Spawned a projectile");
			break;
		}
	}
}

void GameManager::SetGameState(GameState _state)
{
	FlushCurrentEntities(); 

	switch (_state)
	{
		case GameManager::SPLASH_SCREEN:
		{
			Background* pSplash = new Background("../data/splash.jpg", true, Background::FadeType::IN);
			break;
		}
		case GameManager::BOOT_MENU:
		{
			BootMenuManager::GetInstance()->InitBootMenu();
			break;
		}
		case GameManager::GAME:
		{
			InitLevel();
			break;
		}
	}

	mGameState = _state;
}

std::vector<Entity*> GameManager::GetCurrentEntityList()
{
	return mCurrentEntityList;
}

std::vector<Entity*> GameManager::GetCurrentEnemyList()
{
	if (GameManager::GAME)
	{
		return mCurrentEnemyList; 
	}
}

void GameManager::RegisterEntity(Entity* _entity)
{
	mCurrentEntityList.push_back(_entity);
}

void GameManager::RegisterEnemy(Entity * _entity)
{
	mCurrentEnemyList.push_back(_entity);
}
