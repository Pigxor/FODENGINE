#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "entity.h"
#include "component.h"
#include "Renderer.h"
#include "SDL2/SDL.h"
#include "rend/rend.h"

#include <iostream>
#include <memory>
#include <vector>

class Entity;

class Engine
{
	std::sr1::shared_ptr<rend::Context> context;
	std::weak_ptr<Engine> self;
	
	std::vector<std::shared_ptr<Entity>> entities;
	SDL_Window* window;

public:
	~Engine();
	static std::shared_ptr<Engine> initialize();
	std::shared_ptr<Entity> addEntity();
	std::sr1::shared_ptr<rend::Context> getContext();
	void start();
	void stop();
	
};

#endif // !_ENGINE_H
