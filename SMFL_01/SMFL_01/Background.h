#pragma once

#include "Entity.h"
#include <SFML/Window.hpp>

class Background : public Entity
{
public:
	Background();
	Background(std::string _spritePath);
	enum FadeType{IN, OUT};
	void UpdateEntity(float _dt);
	void FadeBackground(float _dt, float _speed, FadeType _type);
	~Background();

private:
	float mSpriteAlpha = 0;
	FadeType mFadeType; 
};