#pragma once

#include <SFML\Graphics.hpp>
#include <array>

#include "System.h"
#include "Sprite.h"
#include "EntityManager.h"

#define LAYERS_NUMBER 10

class RenderGameSystem : public System
{
public:
	void init(void);
	void update(void);
	void receive(Command command, boost::any data);
	std::array<sf::RenderTexture, LAYERS_NUMBER>& getLayers();
private:
	std::array<sf::RenderTexture, LAYERS_NUMBER> layers;
};