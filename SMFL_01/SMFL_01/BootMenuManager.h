#pragma once

#include "pch.h"
#include "UIText.h"
#include "GameWindow.h"
#include "GameManager.h"

class BootMenuManager
{
public:
	static BootMenuManager* GetInstance();

	enum ButtonSwitchDirection {NEXT, PREVIOUS};
	ButtonSwitchDirection eButtonSwitchDirection; 

	BootMenuManager();
	~BootMenuManager();

	void InitBootMenu(); 

	void SetCurrentSelectedButton(ButtonSwitchDirection _direction); 
	void SetCurrentSelectedButton(int _id); 

	int GetCurrentSelectedButton(); 

	void ExecuteButtonFuntion(); 

private: 
	static BootMenuManager *s_pInstance;
	std::vector<UIText*> bootMenuButtonList;
};

