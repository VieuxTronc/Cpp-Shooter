#include "pch.h"
#include "UIText.h"
#include "DebugCustom.h"

UIText::UIText(string _txt, unsigned int _size, sf::Vector2f _pos)
{
	if (!mFont.loadFromFile("../data/arial.ttf"))
	{
		DebugCustom::Error("COULD NOT LOAD THE FONT");
	}
	else
	{
		mText = sf::Text(_txt, mFont, _size);
		mTextString = _txt;
		mSize = _size; 
		mText.setPosition(_pos);
		mPosition = _pos; 
		mColor = sf::Color(255, 255, 255, 255);
		mText.setFillColor(sf::Color(255, 255, 255, 255));
	}
}

UIText::~UIText()
{
}

void UIText::UpdateText(string _txt)
{

}

void UIText::SetSelected(bool _isSelected)
{
	mIsSelected = _isSelected;

	if (mIsSelected)
		mText.setFillColor(sf::Color::Red);
	else
		mText.setFillColor(sf::Color(mColor));
}

bool UIText::IsSelected()
{
	if (mIsSelected)
		return true;
	else
		return false;
}
