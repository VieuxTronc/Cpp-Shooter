#pragma once

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Manager.h"
#include "UIText.h"

class GameManager : public Manager
{
public:
	GameManager();
	~GameManager();

	static GameManager* GetInstance();

	void InitEntities(); 
	void UpdateEntities(float _dt);
	void CleanEntityList(); 
	//void RemoveEntityFromList(int _id);

	enum EntityType {PLAYER, ENEMY, PROJECTILE};
	void SpawnEntity(EntityType _type, sf::Vector2f _pos, unsigned int _number);

	enum GameState {SPLASH_SCREEN, BOOT_MENU, GAME};
	void SetGameState(GameState _state);
	GameState GetCurrentGameState() { return mGameState; }

	std::vector<Entity*> GetCurrentEntityList(); 
	std::vector<Entity*> GetCurrentEnemyList(); 
	void RegisterBootMenuEntity(Entity* _entity) { bootMenuList.push_back(_entity); }

private:
	static GameManager* s_pInstance; 
	//Splashes
	std::vector<Entity*> splashList;
	//Boot menu 
	std::vector<Entity*> bootMenuList;
	std::vector<UIText*> bootMenuTextList;
	//Game
	std::vector<Entity*> entitiesList;
	std::vector<Entity*> enemiesList;
	
	GameState mGameState;
	EntityType mEntityType; 
};

