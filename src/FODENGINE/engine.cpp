#include "engine.h"





std::shared_ptr<Engine> Engine::initialize()
{
	std::shared_ptr<Engine> engine = std::make_shared<Engine>();
	return engine;
}

std::shared_ptr<Entity> Engine::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	return entity;
}

void Engine::start()
{
	for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
	{

		std::cout << "Entity Update Start" << std::endl;		
		(*it)->Update();
		std::cout << "Entity Update Finish" << std::endl;
	}
}

void Engine::stop()
{
}


