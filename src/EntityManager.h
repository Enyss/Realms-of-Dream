#pragma once

#include <vector>
#include <array>

#include "Component.h"
#include "Position.h"
#include "Sprite.h"


class EntityManager
{
public:
	EntityManager(void);

	static EntityManager & em();

	void init();
	int addEntity();
	int addComponent(ComponentId id, int entity);
	void removeComponent(ComponentId id, int entity);
	void removeEntity(int entity);

	/* Entities table */
	std::vector<std::array<int, _COMPONENT_COUNT_>> entities;

	/* Components tables */
	std::vector<Position> position;
	std::vector<Sprite> sprite;
	int controlled;
};