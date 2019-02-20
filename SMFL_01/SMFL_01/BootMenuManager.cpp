#include "pch.h"
#include "BootMenuManager.h"
#include "UIText.h"
#include "GameWindow.h"
#include "GameManager.h"
#include "DebugCustom.h"

BootMenuManager* BootMenuManager::s_pInstance = nullptr;

BootMenuManager* BootMenuManager::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new BootMenuManager();
	}

	return s_pInstance;
}

BootMenuManager::BootMenuManager()
{
}


BootMenuManager::~BootMenuManager()
{
}

void BootMenuManager::InitBootMenu()
{
	GameWindow* pGamewindow = GameWindow::GetInstance();

	UIText* pUITextPlay = new UIText("Play", 30, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y));
	bootMenuButtonList.push_back(pUITextPlay);

	UIText* pUITextOptions = new UIText("Options", 30, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y + 35.0f));
	bootMenuButtonList.push_back(pUITextOptions);

	UIText* pUITextQuit = new UIText("Quit", 30, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y + 70.0f));

	bootMenuButtonList.push_back(pUITextQuit);

	SetCurrentSelectedButton(0);
}

void BootMenuManager::SetCurrentSelectedButton(ButtonSwitchDirection _direction)
{
	switch (_direction)
	{
	case BootMenuManager::NEXT:
		SetCurrentSelectedButton(GetCurrentSelectedButton() + 1);
		return;
	case BootMenuManager::PREVIOUS:
		SetCurrentSelectedButton(GetCurrentSelectedButton() - 1);
		return;
	default:
		break;
	}
}

void BootMenuManager::SetCurrentSelectedButton(int _id)
{
	if (_id < 0)
		_id = bootMenuButtonList.size() - 1;
	if (_id > bootMenuButtonList.size() - 1)
		_id = 0;

	bootMenuButtonList[_id]->SetSelected(true);
	bootMenuButtonList[_id]->UpdateEntity();

	for (size_t i = 0; i < bootMenuButtonList.size(); i++)
	{
		if (bootMenuButtonList[i]->IsSelected())
		{
			if(i != _id)
			bootMenuButtonList[i]->SetSelected(false);
		}
	}
}

int BootMenuManager::GetCurrentSelectedButton()
{
	int index; 

	for (size_t i = 0; i < bootMenuButtonList.size(); i++)
	{
		if (bootMenuButtonList[i]->IsSelected())
		{
			index = i;
		}
	}
	return index;
}

void BootMenuManager::ExecuteButtonFuntion()
{
	int currentButton = GetCurrentSelectedButton(); 

	switch (currentButton)
	{
	case 0:
		GameManager::GetInstance()->SetGameState(GameManager::GAME);
		return;
	case 1:
		DebugCustom::Log("No Options menu.");
		return;
	case 2:
		GameWindow::GetInstance()->CloseWindow();
		return;
	default:
		break;
	}
}
