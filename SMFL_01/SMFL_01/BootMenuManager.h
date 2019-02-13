#pragma once

#include "pch.h"
#include "UIText.h"
#include "GameWindow.h"
#include "GameManager.h"

class BootMenuManager
{
public:
	static BootMenuManager* GetInstance();
	BootMenuManager();
	~BootMenuManager();
	void InitBootMenu(); 
	std::vector<UIText*> GetCurrentButtonList() { return buttonList; }

private: 
	static BootMenuManager *s_pInstance;
	std::vector<UIText*> buttonList;
};

