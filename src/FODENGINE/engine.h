#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "entity.h"
#include "component.h"
#include "Renderer.h"
#include "SDL2/SDL.h"
#include "rend/rend.h"
#include "audioSource.h"
#include "Transform.h"
#include "Camera.h"
#include "fpController.h"
#include "skyBox.h"
#include "boxCollider.h"
#include "guiRenderer.h"

#include <stb_image.h>
#include <iostream>
#include <memory>
#include <vector>



#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

class Entity;


class Engine
{


	std::weak_ptr<Engine> self;
	float lastT;
	float T;
	
	float diff;
	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Camera>> Cams;
	std::shared_ptr<Camera> activeCam;
	SDL_Window* window;
	ALCdevice* device;
	ALCcontext* acontext;

public:
	float deltaT;
	std::sr1::shared_ptr<rend::Context> context;
	~Engine();
	static std::shared_ptr<Engine> initialize();

	std::shared_ptr<Entity> addEntity(const char* nme);
	std::shared_ptr<Camera> getCamera(int i);
	SDL_Window* getWindow();
	std::shared_ptr<Camera> getActiveCam();
	std::shared_ptr<Camera> addCamera(int angle);
	std::shared_ptr<Entity> Engine::addBox(glm::vec3 pos, glm::vec3 scale,glm::vec3 rots);
	int getCamsSize();

	std::sr1::shared_ptr<rend::Context> getContext();
	void start();
	void stop();
	
	template<class T>
	std::vector<std::shared_ptr<Entity>> getEntities()
	{
		std::vector<std::shared_ptr<Entity>> rtnVec;
		bool rtn;
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			rtn = (*it)->checkComponent<T>();
			if (rtn)
			{
				rtnVec.push_back(*it);
			}

		}
		return rtnVec;
	}

};

#endif // !_ENGINE_H
