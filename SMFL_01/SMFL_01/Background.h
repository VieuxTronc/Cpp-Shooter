#pragma once

#include "Entity.h"
#include <SFML/Window.hpp>

class Background : public Entity
{
public:
	Background();
	enum FadeType{IN, OUT, NONE};
	Background(std::string _spritePath, bool _isFading, FadeType _type);
	void UpdateEntity(float _dt);
	void FadeBackground(float _dt, float _speed);
	~Background();

private:
	float mSpriteAlpha = 0;
	FadeType mFadeType; 
};