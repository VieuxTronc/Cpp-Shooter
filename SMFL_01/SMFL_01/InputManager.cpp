#include "pch.h"
#include "InputManager.h"
#include <SFML/System.hpp>
#include "SFML/Window/Keyboard.hpp"
#include "Player.h"
#include "GameWindow.h"
#include "BootMenuManager.h"
#include "DebugCustom.h"

InputManager* InputManager::s_pInstance = nullptr;

InputManager* InputManager::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new InputManager();
	}

	return s_pInstance;
}

void InputManager::InitInputManager()
{

}

void InputManager::Update(float _dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		Player::GetInstance()->MoveEntity(sf::Vector2f(0.0f, -1.0f), _dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		Player::GetInstance()->MoveEntity(sf::Vector2f(0.0f, 1.0f), _dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		Player::GetInstance()->MoveEntity(sf::Vector2f(-1.0f, 0.0f), _dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Player::GetInstance()->MoveEntity(sf::Vector2f(1.0f, 0.0f), _dt);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (GameManager::GetInstance()->GetCurrentGameState() == GameManager::SPLASH_SCREEN)
		{
			GameManager::GetInstance()->SetGameState(GameManager::BOOT_MENU);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (GameManager::GetInstance()->GetCurrentGameState() == GameManager::GAME)
		{
			Player::GetInstance()->Fire(_dt);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		GameWindow::GetInstance()->CloseWindow();
	}
}

void InputManager::UpdateEvents(sf::Event _event)
{
	//Boot menu
	if (GameManager::GetInstance()->GetCurrentGameState() == GameManager::BOOT_MENU)
	{
		if (_event.type == sf::Event::KeyReleased)
		{
			if (_event.key.code == sf::Keyboard::Up)
			{
				BootMenuManager::GetInstance()->SetCurrentSelectedButton(BootMenuManager::PREVIOUS);
			}
			if (_event.key.code == sf::Keyboard::Down)
			{
				BootMenuManager::GetInstance()->SetCurrentSelectedButton(BootMenuManager::NEXT);
			}
			if (_event.key.code == sf::Keyboard::Enter)
			{
				BootMenuManager::GetInstance()->ExecuteButtonFuntion();
			}
		}
	}
	//Debug
	if (_event.type == sf::Event::KeyPressed)
	{
		if (_event.key.code == sf::Keyboard::F1)
		{
			DebugCustom::Log("Debug toggle");
			DebugCustom::GetInstance()->SetDebugMode(!DebugCustom::GetInstance()->GetDebugState());
		}
		if (_event.key.code == sf::Keyboard::F2)
		{

		}
	}
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}
