#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "entity.h"
#include "component.h"
#include "Renderer.h"

#include <iostream>
#include <memory>
#include <vector>

class Entity;

class Engine
{
	std::weak_ptr<Engine> self;
	std::vector<std::shared_ptr<Entity>> entities;
public:

	static std::shared_ptr<Engine> initialize();
	std::shared_ptr<Entity> addEntity();
	void start();
	void stop();
	
};

#endif // !_ENGINE_H
