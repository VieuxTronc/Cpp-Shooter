#pragma once

#include "pch.h"
#include "GameManager.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GameWindow
{
public:
	GameWindow();
	~GameWindow();

	void CreateWindow();
	void UpdateWindow();
	sf::Vector2u GetWindowSize() { return windowSize; }

private:
	sf::Vector2u windowSize = sf::Vector2u(1280, 720);
	sf::RenderWindow window;
	sf::Time dt; 
	sf::Clock deltaClock;
	GameManager gameManager = GameManager();
};