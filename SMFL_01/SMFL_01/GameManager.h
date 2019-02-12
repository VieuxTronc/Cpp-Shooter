#pragma once

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Manager.h"

class GameManager : public Manager
{
public:
	GameManager();
	~GameManager();

	static GameManager* GetInstance();

	void InitEntities(); 
	void UpdateEntities(float _dt);
	void CleanEntityList(); 
	void RemoveEntityFromList(int _id);

	enum EntityType {PLAYER, ENEMY, PROJECTILE};
	void SpawnEntity(EntityType _type, sf::Vector2f _pos, unsigned int _number);

	enum GameState {BOOT_MENU, GAME};
	void SetGameState(GameState _state);
	GameState GetCurrentGameState() { return mGameState; }

	std::vector<Entity*> GetCurrentEntityList(); 
	std::vector<Entity*> GetCurrentEnemyList(); 

private:
	static GameManager* s_pInstance; 
	std::vector<Entity*> splashList;
	std::vector<Entity*> entitiesList;
	std::vector<Entity*> enemiesList;
	GameState mGameState;
	EntityType mEntityType; 
};

