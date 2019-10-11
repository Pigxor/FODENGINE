#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>

class Engine;

class Entity
{
	Entity();
	~Entity();
	std::weak_ptr<Engine> engine;

public:
	std::shared_ptr<Engine> getCore();

};

#endif