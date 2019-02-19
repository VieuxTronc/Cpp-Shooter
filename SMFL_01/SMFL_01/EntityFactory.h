#pragma once
class EntityFactory
{
public:
	static EntityFactory* GetInstance();

	EntityFactory();
	~EntityFactory();

	enum EntityType { PLAYER, ENEMY, PROJECTILE };
	EntityType eEntityType; 

	void CreateEntity(EntityType _type, int _number);
	//Create entity from file ? 

private:
	static EntityFactory* s_pInstance;
};

