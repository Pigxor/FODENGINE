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
#include "physics.h"
#include "2dAnimation.h"
#include "3dAnimation.h"

#include <stb_image.h>
#include <iostream>
#include <memory>
#include <vector>
#include <SDL2/SDL_gamecontroller.h>


#define WINDOW_WIDTH 1024 ///< Defines the Window width used
#define WINDOW_HEIGHT 760 ///< Defines the Window height used

class Entity;

/**
* The primary Engine object
*/
class Engine
{

	std::weak_ptr<Engine> self; ///< Pointer to itself
	float lastT; ///< Last Ticks - used for calculating delta time
	float T;	///< Time - used for calculating delta time
	float diff; ///< Difference - used for capping the framerate
	int inputNum; ///< Value passed into FPControllers to use Game Controllers for inputs
	std::vector<std::shared_ptr<Entity>> entities; ///< Vector of all the entities
	std::vector<std::shared_ptr<Camera>> Cams; ///< Vector of all the cameras
	std::shared_ptr<Camera> activeCam; ///< Pointer to teh currently active camera
	SDL_Window* window; ///< Window
	ALCdevice* device; ///< Audio Device
	ALCcontext* acontext; ///< Audio Context

public:
	float deltaT; ///< Value for Delta Time
	std::sr1::shared_ptr<rend::Context> context; ///< The context for loading things in
	~Engine();
	/**
	* \brief Initialises the engine
	*/
	static std::shared_ptr<Engine> initialize();
	/**
	* \brief Adds an Entity to the engine
	* Also adds a Transform component by default
	*/
	std::shared_ptr<Entity> addEntity(const char* nme);
	/**
	* \brief Returns a specified camera from the list of cameras
	*/
	std::shared_ptr<Camera> getCamera(int i);
	/**
	* \brief Returns the current Window
	*/
	SDL_Window* getWindow();
	/**
	* \brief Returns the active camera
	*/
	std::shared_ptr<Camera> getActiveCam();
	/**
	* \brief Adds a camera with a transform
	*/
	std::shared_ptr<Camera> addCamera(int angle);
	/**
	* \brief Adds a cube object with a transform and hit box
	*/
	std::shared_ptr<Entity> Engine::addBox(glm::vec3 pos, glm::vec3 scale,glm::vec3 rots, const char* nme);
	/**
	* \brief Returns how many cameras there are
	*/
	int getCamsSize();
	/**
	* \brief Gets the context
	*/
	std::sr1::shared_ptr<rend::Context> getContext();
	/**
	* \brief Starts the engine nd contains the main update adn display loops
	*/
	void start();
	/**
	* \brief Stops the Camera
	*/
	void stop();
	/**
	* \brief Returns the delta time
	*/
	float getDeltaT();
	/**
	* \brief Returns the controller input value
	*/
	float getInputNum();
	SDL_GameController *controller = nullptr; ///< Pointer to the Game Controller
	
	/**
	* \brief Returns entities with a desired value
	*/
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
