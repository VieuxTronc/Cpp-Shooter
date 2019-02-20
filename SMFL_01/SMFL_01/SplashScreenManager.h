#pragma once

#include "pch.h"

class SplashScreenManager
{
public:
	static SplashScreenManager* GetInstance();
	SplashScreenManager();
	~SplashScreenManager();

	void InitSplashScreen(); 

private:
	static SplashScreenManager* s_pInstance;
};

