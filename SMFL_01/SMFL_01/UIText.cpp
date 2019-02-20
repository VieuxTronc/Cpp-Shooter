#include "pch.h"
#include "UIText.h"
#include "DebugCustom.h"
#include "GameManager.h"

UIText::UIText(string _txt, unsigned int _size)
{
	if (!mFont.loadFromFile("../data/arial.ttf"))
	{
		DebugCustom::Error("COULD NOT LOAD THE FONT");
	}
	else
	{
		mText = sf::Text(_txt, mFont, _size);
		mTextString = _txt;
		mTextSize = _size; 
		mTextColor = sf::Color(255, 255, 255, 255);

		mText.setFillColor(mTextColor);
	}

	GameManager::GetInstance()->RegisterEntity(this);
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
		mText.setFillColor(sf::Color(mTextColor));
}

bool UIText::IsSelected()
{
	if (mIsSelected)
		return true;
	else
		return false;
}
