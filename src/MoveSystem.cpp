#include "MoveSystem.h"

void MoveSystem::init(void)
{
}

void MoveSystem::update(void)
{
}

void MoveSystem::receive(Command command, boost::any data)
{
	switch (command)
	{
	case MOVE_CONTROLLABLE:
		move(EntityManager::em().controlled, boost::any_cast<Vector2i>(data));
		break;
	case MOVE_ENTITY:
		std::pair<int, Vector2i> d = boost::any_cast<std::pair<int, Vector2i>>(data);
		move(d.first, d.second);
		break;
	}
}

void MoveSystem::move(int entity, Vector2i movement)
{
	int idPosition = EntityManager::em().entities[entity][POSITION_COMPONENT];
	if (idPosition >= 0)
	{
		Vector3i v;
		v.x = movement.x;
		v.y = movement.y;
		v.lvl = 0;
		EntityManager::em().position[idPosition].pos += v;
	}
}
