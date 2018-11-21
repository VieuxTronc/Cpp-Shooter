#include "pch.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "Entity.h"
#include "Player.h"

GameWindow::GameWindow()
{
	printf("Window Object created.\n");
}

GameWindow::~GameWindow()
{
}

void GameWindow::CreateWindow()
{
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "");
	printf("Window created.\n");
	gameManager.InitEntities();
}

void GameWindow::UpdateWindow()
{
	while (window.isOpen())
	{
		dt = deltaClock.restart();
		window.setTitle(std::to_string(1.0f / dt.asSeconds()));

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
			gameManager.ListenToInputs();
		}

		// Clear screen
		window.clear();

		//Update entities
		gameManager.UpdateEntities();
	
		//Draw
		for (size_t i = 0; i < gameManager.GetEntityCount(); i++)
		{
			window.draw(gameManager.GetEntity(i)->GetSprite());
		}
		
		// Update the window
		window.display();
	}
}