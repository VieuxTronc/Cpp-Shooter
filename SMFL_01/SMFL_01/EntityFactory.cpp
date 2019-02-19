#include "pch.h"
#include "EntityFactory.h"

EntityFactory* EntityFactory::s_pInstance = nullptr;

EntityFactory* EntityFactory::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new EntityFactory();
	}

	return s_pInstance;
}

EntityFactory::EntityFactory()
{
}


EntityFactory::~EntityFactory()
{
}
