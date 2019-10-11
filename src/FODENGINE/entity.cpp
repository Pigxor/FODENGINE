#include"entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

std::shared_ptr<Engine> Entity::getCore()
{
	return std::shared_ptr<Engine>();
}
