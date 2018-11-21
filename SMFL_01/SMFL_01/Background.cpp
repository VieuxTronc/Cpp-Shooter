#include "pch.h"
#include "Background.h"
#include "GameWindow.h"

Background::Background()
{
}

Background::Background(std::string _spritePath)
{
	GameWindow* pWindow = new GameWindow();

	sf::Vector2f pos = sf::Vector2f(pWindow->GetWindowSize().x / 2, pWindow->GetWindowSize().y / 2);
	pos.x -= mTexture.getSize().x;
	pos.y -= mTexture.getSize().y;

	CreateEntity(pos, _spritePath);
}

Background::~Background()
{
}
