#include "pch.h"
#include "SplashScreenManager.h"
#include "Background.h"

SplashScreenManager* SplashScreenManager::s_pInstance = nullptr;

SplashScreenManager* SplashScreenManager::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new SplashScreenManager();
	}

	return s_pInstance;
}

SplashScreenManager::SplashScreenManager()
{
}


SplashScreenManager::~SplashScreenManager()
{
}

void SplashScreenManager::InitSplashScreen()
{
	Background* pSplash = new Background("../data/splash.jpg", true, Background::FadeType::IN);
}
