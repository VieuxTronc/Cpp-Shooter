#pragma once

#include "UIText.h"

class HUDManager
{
public:
	static HUDManager* GetInstance();
	HUDManager();
	~HUDManager();

	void InitHUDManager(); 

	UIText* GetPointsCounter() { return mPointCounter; }

private:
	static HUDManager* s_pInstance;
	UIText* mPointCounter; 
};

