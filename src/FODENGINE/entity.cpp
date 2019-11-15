#include"entity.h"
#include "component.h"

void Entity::Update()
{
	
	for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{	
		(*it)->onUpdate();
	}
		
}

void Entity::Display()
{
	for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDisplay();

	}
}


std::shared_ptr<Engine> Entity::getEngine(std::shared_ptr<Engine> _engine)
{
	return engine.lock();
}
