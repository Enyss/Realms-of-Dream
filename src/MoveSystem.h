#pragma once

#include "boost\any.hpp"
#include "Position.h"

#include "Vectors.h"
#include "EntityManager.h"
#include "System.h"

class MoveSystem : public System
{
public :
	void init(void);
	void update(void);
	void receive(Command command, boost::any data);
private :
	void move(int entity, Vector2i movement);
};