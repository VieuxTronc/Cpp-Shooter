#pragma once

#include "Entity.h"
#include <SFML/Window.hpp>

class Background : public Entity
{
public:
	Background();
	Background(std::string _spritePath);
	~Background();
};

