#pragma once

#include "EntityManager.h"
#include "RenderManager.h"

#include "Component.h"
#include "Position.h"
#include "Sprite.h"


class EntityFactory
{
public:
	static EntityFactory & ef();

	void init();

	int createEntity(std::string entityType);

private:
	
};