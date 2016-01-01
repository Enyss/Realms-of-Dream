#include "RenderManager.h"

RenderManager::RenderManager()
{
}

RenderManager & RenderManager::rm()
{
	static RenderManager rm;
	return rm;
}

void RenderManager::init()
{
	window.create(sf::VideoMode(800, 600), "Realms of Dream");
	tileSet.loadFromFile("gfx/tileset.png"); 
}

void RenderManager::render()
{
	window.clear(sf::Color::Black);
	MapManager & mm = MapManager::mm();
	Vector3i pos = EntityManager::em().position[EntityManager::em().controlled].pos;
	for (int x = - 32; x < 32; x++)
	{
		for (int y = - 32; y <  32; y++)
		{
			sf::Sprite spr = mm.getSprite(x+pos.x, y+pos.y);
			spr.setPosition(32 * (x + 32), 32 * (y + 32));
			window.draw(spr);
		}
	}


	RenderGameSystem* rgs = static_cast<RenderGameSystem*>(SystemManager::sm().getSystem(RENDER_SYSTEM));
	for (int i = 0; i < LAYERS_NUMBER; i++)
	{
		window.draw( sf::Sprite(rgs->getLayers()[i].getTexture()) );
	}

	window.display();
}

sf::Texture & RenderManager::getTileset()
{
	return tileSet;
}

sf::RenderWindow& RenderManager::getWindow()
{
	return window;
}
