#pragma once

#include "Manager.h"
#include "Player.h"
#include "GameWindow.h"

class InputManager : public Manager
{
public:
	static InputManager* GetInstance();

	void InitInputManager(); 
	void Update( float _dt);
	void UpdateEvents(sf::Event _event);

private:
	InputManager();
	~InputManager();
	static InputManager* s_pInstance;
};

