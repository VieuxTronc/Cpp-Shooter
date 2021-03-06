#pragma once

#include "pch.h"
#include "GameManager.h"
#include "BootMenuManager.h"
#include "InputManager.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameWindow
{
public:
	static GameWindow* GetInstance();
	GameWindow();
	~GameWindow();

	void CreateWindow();
	void UpdateWindow();
	sf::Vector2u GetWindowSize() { return windowSize; }
	sf::Vector2f GetWindowSizef() { return windowSizef; }
	sf::Vector2f GetWindowMiddlePos() { return mWindowMiddlePos; }
	void CloseWindow(); 

private:
	static GameWindow* s_pInstance;
	GameManager* pGameManager;
	//BootMenuManager* pBootMenuManager; 
	sf::Vector2u windowSize = sf::Vector2u(1280, 720);
	sf::Vector2f windowSizef = sf::Vector2f(1280.0f, 720.0f);
	sf::Vector2f mWindowMiddlePos; 
	float currentFrameRate;
	float maxFrameRate = 120.0f; 
	sf::RenderWindow window;
	sf::Time dt; 
	sf::Clock deltaClock;
	float mTimeScale = 1.0f;
};