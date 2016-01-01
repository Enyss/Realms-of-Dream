#include "RenderGameSystem.h"

void RenderGameSystem::init(void)
{
	for (std::array<sf::RenderTexture, 10>::iterator it = layers.begin(); it != layers.end(); it++)
	{
		it->create(800,600);
	}
}

void RenderGameSystem::update(void)
{
	for (std::array<sf::RenderTexture, 10>::iterator it = layers.begin(); it != layers.end(); it++)
	{
		it->clear(sf::Color(0, 0, 0, 0));
	}
	for (std::vector<Sprite>::iterator it = EntityManager::em().sprite.begin(); it != EntityManager::em().sprite.end(); ++it)
	{
		for (std::map<int, sf::Sprite>::iterator i = it->sprites.begin(); i != it->sprites.end(); ++i)
		{
			int x = 32 * EntityManager::em().position[EntityManager::em().entities[it->entity][POSITION_COMPONENT]].pos.x;
			int y = 32 * EntityManager::em().position[EntityManager::em().entities[it->entity][POSITION_COMPONENT]].pos.y;
			i->second.setPosition(x, y);
			layers[i->first].draw(i->second);
		}
	}
	for (std::array<sf::RenderTexture, 10>::iterator it = layers.begin(); it != layers.end(); it++)
	{
		it->display();
	}
}

void RenderGameSystem::receive(Command command, boost::any data)
{
}

std::array<sf::RenderTexture, LAYERS_NUMBER>& RenderGameSystem::getLayers()
{
	return layers;
}
