#include "InputManager.h"

InputManager::InputManager()
{
}

void InputManager::update()
{
	sf::RenderWindow& window = RenderManager::rm().getWindow();
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Numpad2 :
				SystemManager::sm().receive(MOVE_CONTROLLABLE, Vector2i(0, 1));
				break;
			case sf::Keyboard::Numpad4:
				SystemManager::sm().receive(MOVE_CONTROLLABLE, Vector2i(-1, 0));
				break;
			case sf::Keyboard::Numpad6:
				SystemManager::sm().receive(MOVE_CONTROLLABLE, Vector2i(1, 0));
				break;
			case sf::Keyboard::Numpad8:
				SystemManager::sm().receive(MOVE_CONTROLLABLE, Vector2i(0, -1));
				break;
			}
		}
	}


}
