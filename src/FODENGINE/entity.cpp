#include"entity.h"


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
}

std::shared_ptr<Engine> Entity::getCore()
{
	return std::shared_ptr<Engine>();
}
