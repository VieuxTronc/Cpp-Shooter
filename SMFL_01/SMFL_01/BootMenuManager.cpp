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

	UIText* pUITextPlay = new UIText("Play", 30.0f, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y));
	bootMenuEntityList.push_back(pUITextPlay);
	bootMenuButtonList.push_back(pUITextPlay);

	UIText* pUITextOptions = new UIText("Options", 30.0f, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y + 35.0f));
	bootMenuEntityList.push_back(pUITextOptions);
	bootMenuButtonList.push_back(pUITextOptions);

	UIText* pUITextQuit = new UIText("Quit", 30.0f, sf::Vector2f(pGamewindow->GetWindowMiddlePos().x - 35.0f, pGamewindow->GetWindowMiddlePos().y + 70.0f));
	bootMenuEntityList.push_back(pUITextQuit);
	bootMenuButtonList.push_back(pUITextQuit);

	SetCurrentSelectedButton(0);
}

void BootMenuManager::SetCurrentSelectedButton(ButtonSwitchDirection _direction)
{
	int i = GetCurrentSelectedButton();
	DebugCustom::Log(to_string(i));
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
		_id = bootMenuEntityList.size() - 1;

	if (_id > bootMenuEntityList.size() - 1)
		_id = 0;

	for (size_t i = 0; i < bootMenuEntityList.size(); i++)
	{
		if(i == _id)
		bootMenuButtonList[_id]->SetSelected(true);
		else
		bootMenuButtonList[_id]->SetSelected(false);
	}
}

int BootMenuManager::GetCurrentSelectedButton()
{
	int index; 

	for (size_t i = 0; i < bootMenuEntityList.size(); i++)
	{
		if (bootMenuButtonList[i]->IsSelected())
		{
			index = i;

			if (index >= bootMenuEntityList.size())
				return index =- 1;
		}
	}

	return index;
}
