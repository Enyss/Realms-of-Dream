#include "SystemManager.h"

SystemManager::SystemManager(void)
{
	systems = std::vector<System*>(_SYSTEM_COUNT_);
	im = new InputManager();
}

SystemManager & SystemManager::sm()
{
	static SystemManager sm;
	return sm;
}

void SystemManager::init()
{
	// system creation
	systems[MOVE_SYSTEM] = new MoveSystem();
	systems[RENDER_SYSTEM] = new RenderGameSystem();

	// system initialization 
	systems[MOVE_SYSTEM]->init();
	systems[RENDER_SYSTEM]->init();
}

void SystemManager::mainLoop()
{
	im->update();
	systems[MOVE_SYSTEM]->update();
	systems[RENDER_SYSTEM]->update();
}

GameState SystemManager::getState()
{
	return state;
}

System * SystemManager::getSystem(SystemId systemId)
{
	return systems[systemId];
}

void SystemManager::receive(Command command, boost::any data)
{
	switch (command)
	{
	case MOVE_CONTROLLABLE :
		systems[MOVE_SYSTEM]->receive(command, data);
		break;
	}
}
