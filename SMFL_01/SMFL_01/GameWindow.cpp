#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"
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
	pGameManager = GameManager::GetInstance(); 
	pGameManager->InitEntities();
	pGameManager->SetGameState(GameManager::SPLASH_SCREEN);
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
			window.draw(pGameManager->GetCurrentEntityList()[i]->GetSprite());

			if(pGameManager->GetCurrentGameState() != pGameManager->SPLASH_SCREEN)
			window.draw(pGameManager->GetCurrentTextList()[i]->GetText());
		}
		
		// Update the window
		window.display();
	}
}

void GameWindow::CloseWindow()
{
	//GameManager::GetInstance()->CleanList(GameManager::GetInstance()->GetCurrentEntityList());
	window.close();
}
