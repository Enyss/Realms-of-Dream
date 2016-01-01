#pragma once

#include <array>
#include <map>
#include <SFML\graphics.hpp>

#include "Vectors.h"
#include "RenderManager.h"

typedef struct
{
	const int w = 16;
	const int h = 16;
	std::array<int,256> terrainType;
	std::array<sf::Sprite, 256> terrainSprites;
} Chunk;

class MapManager
{
public :
	static MapManager & mm();
	sf::Sprite getSprite(int x, int y);
	void createMap();
private :
	std::map<Vector3i, Chunk> currentChunks;
};