#include "pch.h"
#include "Background.h"
#include "GameWindow.h"

Background::Background()
{
}

Background::Background(std::string _spritePath, bool _isFading, FadeType _type)
{
	GameWindow* pGameWindow = GameWindow::GetInstance();

	sf::Vector2f wSize = pGameWindow->GetWindowSizef();
	sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f);

	CreateEntity(pos, _spritePath);

	float sizeRatioX = wSize.x / mTexture.getSize().x;
	float sizeRatioY = wSize.y / mTexture.getSize().y;

	mSprite.setScale(sf::Vector2f(sizeRatioX, sizeRatioY));
	mSprite.setPosition(mPosition);

	mFadeType = _type;
}

void Background::UpdateEntity(float _dt)
{
	FadeBackground(_dt, 29.0f);
}

void Background::FadeBackground(float _dt, float _speed)
{
	switch (mFadeType)
	{
	case Background::IN:
		mSpriteAlpha += _speed * _dt;

		if (mSpriteAlpha >= 255.0f)
		{
			GameManager::GetInstance()->SetGameState(GameManager::GAME);
			return;
		}
		break;
	case Background::OUT:
		mSpriteAlpha -= _speed * _dt;

		if (mSpriteAlpha <= 0.0f)
		{
			GameManager::GetInstance()->SetGameState(GameManager::GAME);
			return;
		}
		break;
	case Background::NONE:
		mSpriteAlpha = 255.0f;
		break;
	default:
		break;
	}

	mSprite.setColor(sf::Color(255, 255, 255, static_cast<int>(mSpriteAlpha)));
}

Background::~Background()
{
}