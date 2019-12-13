#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "entity.h"
#include "component.h"
#include "Renderer.h"
#include "pbr.h"
#include "SDL2/SDL.h"
#include "rend/rend.h"
#include "audioSource.h"
#include "Transform.h"
#include "Camera.h"

#include <iostream>
#include <memory>
#include <vector>

class Entity;


class Engine
{


	std::weak_ptr<Engine> self;
	float lastT;
	float T;
	
	float diff;
	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Entity>> cubeCams;
	std::vector<std::shared_ptr<Entity>> Cams;

	SDL_Window* window;
	ALCdevice* device;
	ALCcontext* acontext;

public:
	float deltaT;
	std::sr1::shared_ptr<rend::Context> context;
	~Engine();
	static std::shared_ptr<Engine> initialize();

	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Camera> getCamera(int i);
	void addCamera(int angle);

	std::sr1::shared_ptr<rend::Context> getContext();
	void start();
	void stop();
	
};

#endif // !_ENGINE_H
