#include <SFML/Graphics.hpp>
#include <iostream>

#include "SystemManager.h"
#include "RenderManager.h"
#include "EntityManager.h"
#include "EntityFactory.h"

int main()
{
	SystemManager::sm().init();
	RenderManager::rm().init();
	EntityManager::em().init();
	EntityFactory::ef().init();
	MapManager::mm().createMap();


	while (SystemManager::sm().getState() != QUIT)
	{
		SystemManager::sm().mainLoop();
		RenderManager::rm().render();
	}
	return 0;
}