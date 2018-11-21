#pragma once

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void InitEntities(); 
	void ListenToInputs();
	void UpdateEntities();
	Entity* GetEntity(int _id) { return entitiesList[_id]; }
	unsigned int GetEntityCount() { return entitiesList.size(); }

private:
	std::vector<Entity*> entitiesList;
	Player* pPlayer; 
};

