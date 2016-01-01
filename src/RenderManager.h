#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <array>

#include "MapManager.h"
#include "SystemManager.h"
#include "RenderGameSystem.h"

#include "Component.h"
#include "Position.h"
#include "Sprite.h"


class RenderManager
{
public:
	RenderManager();

	static RenderManager & rm();

	void init();
	void render();

	sf::Texture & getTileset();
	sf::RenderWindow& getWindow();
private:
	sf::Texture tileSet;
	sf::RenderWindow window;
};