#pragma once

#include <SFML\Window.hpp>

#include "SystemManager.h"
#include "RenderManager.h"

class InputManager
{
public:
	InputManager();
	void update();
private:
	sf::Window window;
};