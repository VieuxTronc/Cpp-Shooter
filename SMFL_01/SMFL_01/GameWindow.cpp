#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "BootMenuManager.h"
#include "Entity.h"
#include "Player.h"
#include "DebugCustom.h"

GameWindow* GameWindow::s_pInstance = nullptr;

GameWindow* GameWindow::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new GameWindow();
	}

	return s_pInstance;
}

GameWindow::GameWindow()
{
	DebugCustom::Log("Window Object created.");
}

GameWindow::~GameWindow()
{
}

void GameWindow::CreateWindow()
{
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "");
	window.setMouseCursorVisible(false);
	window.setKeyRepeatEnabled(false);
	mWindowMiddlePos = sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f);

	pGameManager = GameManager::GetInstance(); 
	pGameManager->InitEntities();
	pGameManager->SetGameState(GameManager::SPLASH_SCREEN);

	//pBootMenuManager = BootMenuManager::GetInstance();

	DebugCustom::Log("Window created.");
}

void GameWindow::UpdateWindow()
{
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		dt = dt * mTimeScale;

		currentFrameRate = 1.0f / dt.asSeconds();

		if (currentFrameRate > maxFrameRate)
		{
			currentFrameRate = maxFrameRate;
		}

		window.setTitle(std::to_string(currentFrameRate) + " FPS / " + std::to_string(dt.asSeconds()) + " Delta time");

		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();

			InputManager::GetInstance()->UpdateEvents(event);
		}

		if (window.hasFocus())
		{
			InputManager::GetInstance()->Update(dt.asSeconds());

		}

		// Clear screen
		window.clear();

		//Update entities
		pGameManager->UpdateEntities(dt.asSeconds());

		//Draw
		for (size_t i = 0; i < pGameManager->GetCurrentEntityList().size(); i++)
		{
			window.draw(*pGameManager->GetCurrentEntityList()[i]->GetDrawable());
			
			if (DebugCustom::GetInstance()->GetDebugState())
			{
				window.draw(*pGameManager->GetCurrentEntityList()[i]->GetDebugDrawable());
			}
		}
		
		// Update the window
		window.display();
	}
}

void GameWindow::CloseWindow()
{
	window.close();
}
