#pragma once

#include <boost/any.hpp>

#include "Command.h"

/* SystemsId enum */
enum SystemId {
	INPUT_SYSTEM,
	MOVE_SYSTEM,
	RENDER_SYSTEM,

	// Keep at the end !!! //
	_SYSTEM_COUNT_
};

/* System base class */
class System
{
public :
	virtual void init(void) = 0;
	virtual void update(void) = 0;
	virtual void receive(Command command, boost::any data) = 0;
	virtual ~System() {};
};