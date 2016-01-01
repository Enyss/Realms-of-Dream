#include "EntityManager.h"

EntityManager::EntityManager(void)
{
}

EntityManager & EntityManager::em()
{
	static EntityManager em;
	return em;
}

void EntityManager::init()
{
	controlled = 0;
}

int EntityManager::addEntity()
{
	int e = entities.size();
	entities.push_back(std::array<int, _COMPONENT_COUNT_>() );
	entities[e].fill(-1);
	return e;
}

int EntityManager::addComponent(ComponentId id, int entity)
{
	int c;
	switch (id)
	{
	case POSITION_COMPONENT :
		c = position.size();
		position.push_back(Position(0,0,0));
		position[c].entity = entity;
		break;
	case SPRITE_COMPONENT:
		c = sprite.size();
		sprite.push_back(Sprite());
		sprite[c].entity = entity;
		break;
	default:
		break;
	}
	entities[entity][id] = c;
	return 0;
}
