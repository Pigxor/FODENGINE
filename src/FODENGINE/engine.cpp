#include "engine.h"





std::shared_ptr<Engine> Engine::initialize()
{
	std::shared_ptr<Engine> engine = std::make_shared<Engine>();
	engine->self = engine;
	return engine;
}

std::shared_ptr<Entity> Engine::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	entity->engine = self;
	entity->self = entity;
	return entity;
}

void Engine::start()
{

	bool quit = false;

	while (!quit)
	{
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{

			std::cout << "Entity Update Start" << std::endl;
			(*it)->Update();
			std::cout << "Entity Update Finish" << std::endl;
		}
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			std::cout << "Component Display" << std::endl;
			(*it)->Display();

		}
	}
}

void Engine::stop()
{
}


