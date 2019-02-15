#pragma once

#include "pch.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"

class UIText : public Entity
{
public:
	UIText(string _txt, unsigned int _size);
	~UIText();

	sf::Drawable* GetDrawable() { return &mText; }

	void SetEntityPosition(sf::Vector2f _pos) { mText.setPosition(_pos); }

	sf::Vector2f GetTextSize() { return sf::Vector2f(mText.getLocalBounds().width, mText.getLocalBounds().height); }
	void UpdateText(string _txt); 

	void SetSelected(bool _isSelected);
	bool IsSelected();

private: 
	sf::Text mText;
	sf::Font mFont; 
	string mTextString; 
	unsigned int mTextSize; 
	sf::Color mTextColor; 

	bool mIsSelected; 
};

