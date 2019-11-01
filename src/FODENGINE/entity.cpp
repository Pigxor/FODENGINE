#include"entity.h"
#include "component.h"

void Entity::Update()
{
	
	for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		std::cout << "Component Update Start" << std::endl;
		(*it)->onUpdate();
	}
		
}

void Entity::Display()
{
	for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		std::cout << "Component Draw" << std::endl;
		(*it)->onDisplay();

	}
}


std::shared_ptr<Engine> Entity::getEngine(std::shared_ptr<Engine> _engine)
{
	engine = _engine;
	return engine.lock();
}
