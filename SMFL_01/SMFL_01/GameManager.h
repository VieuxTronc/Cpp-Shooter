#pragma once

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "UIText.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	static GameManager* GetInstance();

	void InitGame(); 
	void InitLevel();

	void UpdateEntities(float _dt);

	void CleanCurrentEntityList(); 
	void FlushCurrentEntities();
	//void RemoveEntityFromList(int _id);

	enum EntityType {PLAYER, ENEMY, PROJECTILE}; // Need entity factory ! 
	void SpawnEntity(EntityType _type, sf::Vector2f _pos, unsigned int _number); // Need entity factory ! 

	enum GameState {SPLASH_SCREEN, BOOT_MENU, GAME};
	void SetGameState(GameState _state);
	GameState GetCurrentGameState() { return mGameState; }

	std::vector<Entity*> GetCurrentEntityList(); 
	std::vector<Entity*> GetCurrentEnemyList(); 

	void RegisterEntity(Entity* _entity);
	void RegisterEnemy(Entity* _entity);

private:
	static GameManager* s_pInstance; 

	//Enemies -> no need for that, find another way to sort enemies out of the mCurrentEntityList
	std::vector<Entity*> mCurrentEnemyList;

	std::vector<Entity*> mCurrentEntityList;
	
	GameState mGameState;
	EntityType mEntityType; 
};

