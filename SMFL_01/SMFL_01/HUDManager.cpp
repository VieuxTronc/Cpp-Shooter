#include "pch.h"
#include "HUDManager.h"
#include "UIText.h"

HUDManager* HUDManager::s_pInstance = nullptr;

HUDManager* HUDManager::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new HUDManager();
	}

	return s_pInstance;
}

HUDManager::HUDManager()
{
}


HUDManager::~HUDManager()
{
}

void HUDManager::InitHUDManager()
{
	mPointCounter = new UIText("Points : ", 35);
	mPointCounter->SetEntityPosition(sf::Vector2f(0.0f, 0.0f));
}
