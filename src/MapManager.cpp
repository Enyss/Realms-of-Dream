#include "MapManager.h"

MapManager & MapManager::mm()
{
	static MapManager mm;
	return mm;
}

sf::Sprite MapManager::getSprite(int x, int y)
{
	Vector3i v = { floor(x / 16), floor(y / 16), 0 };
	if (currentChunks.count(v) == 1)
	{
		int i = (x%16 + 16)%16 + 16 * ((y % 16 + 16) % 16);
		return currentChunks[v].terrainSprites[ i ];
	}
	return sf::Sprite();
}

void MapManager::createMap()
{
	for (int x = -10; x < 10; x++)
	{
		for (int y = -10; y < 10; y++)
		{
			Vector3i v = { x, y, 0 };
			currentChunks[v].terrainType.fill(0);
			sf::Sprite sprite;
			sprite.setTexture(RenderManager::rm().getTileset());
			sprite.setTextureRect(sf::IntRect(59 * 32, 14 * 32, 32, 32));
			currentChunks[v].terrainSprites.fill(sprite);
		}
	}
}
