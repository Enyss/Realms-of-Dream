#pragma once

#include <SFML\Graphics.hpp>

#include "Component.h"

struct Sprite : public Component
{
	std::map<int, sf::Sprite> sprites;
};