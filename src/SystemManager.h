#pragma once

#include <vector>

class InputManager;

#include "InputManager.h"

#include "System.h"
#include "MoveSystem.h"
#include "RenderGameSystem.h"

enum GameState {
	MENU,
	PLAY,
	QUIT
};

class SystemManager
{
public :
	// constructor
	SystemManager(void);

	// singleton instance 
	static SystemManager & sm();

	// methods
	void init();
	void mainLoop();
	GameState getState();

	System * getSystem(SystemId);

	void receive(Command command, boost::any data);
private :
	InputManager * im;
	std::vector<System*> systems;
	GameState state;
};