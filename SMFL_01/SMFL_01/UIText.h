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

	void UpdateText(string _text) { mText.setString(_text); }

	void SetEntityPosition(sf::Vector2f _pos) { mText.setPosition(_pos); }

	sf::Vector2f GetTextSize() { return sf::Vector2f(mText.getLocalBounds().width, mText.getLocalBounds().height); }

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

