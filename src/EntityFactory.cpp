#include "EntityFactory.h"

EntityFactory & EntityFactory::ef()
{
	static EntityFactory ef;
	return ef;
}

void EntityFactory::init()
{
	createEntity("player");
}

int EntityFactory::createEntity(std::string entityType)
{
	int player = EntityManager::em().addEntity();

	int pos = EntityManager::em().addComponent(POSITION_COMPONENT, player);
	EntityManager::em().position[pos] = Position(0,0,0);

	int sprite = EntityManager::em().addComponent(SPRITE_COMPONENT, player);
	EntityManager::em().sprite[sprite].sprites[9].setTexture(RenderManager::rm().getTileset());
	EntityManager::em().sprite[sprite].sprites[9].setTextureRect(sf::IntRect(64, 64, 32, 32));

	return player;
}
