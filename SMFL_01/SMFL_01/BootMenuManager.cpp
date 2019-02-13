#include "pch.h"
#include "BootMenuManager.h"
#include "UIText.h"
#include "GameWindow.h"
#include "GameManager.h"

BootMenuManager* BootMenuManager::s_pInstance = nullptr;

BootMenuManager* BootMenuManager::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new BootMenuManager();
	}

	return s_pInstance;
}

void BootMenuManager::InitBootMenu()
{
	GameWindow* pGamewindow = GameWindow::GetInstance();

	UIText* pUITextPlay = new UIText("Play", 30.0f, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y));
	buttonList.push_back(pUITextPlay);

	UIText* pUITextOptions = new UIText("Options", 30.0f, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y + 35.0f));
	buttonList.push_back(pUITextOptions);

	UIText* pUITextQuit = new UIText("Quit", 30.0f, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y + 70.0f));
	buttonList.push_back(pUITextQuit);
}

BootMenuManager::BootMenuManager()
{
}


BootMenuManager::~BootMenuManager()
{
}
