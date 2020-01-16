#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <iostream>
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "rend/rend.h"
#include "glm/glm.hpp"


class Entity;
class Engine;

/**
* \brief Base class that other 'Components' inherit from
*/
class Component
{
	friend Entity;
protected: 
	std::weak_ptr<Entity> entity; ///< Weak pointer to the entity this component is attached to
	std::weak_ptr<Engine> engine; ///< Weak pointer to the engine
	//virtual void onCreate();
	//virtual void onStart();
	/**
	* \brief Update loop, virtual so that other component can have their own
	*/
	virtual void onUpdate();
	/**
	* \brief Display loop, virtual so that other component can have their own
	*/
	virtual void onDisplay();
	//onInit();
	bool active; ///< Bool controls if certain aspects of a component happen
public:
	/**
	* \brief Sets the conponent active bool
	*/
	void setActive(bool Active);
	/**
	* \brief Checks if the component is active
	*/
	bool getActive();
	const char* name; ///< Name variable - equivalent to tags in Unity
	/**
	* \brief Locks the weak pointer so the engine can be accesed
	*/
	std::shared_ptr<Engine> getEngine();
	/**
	* \brief Locks the weak pointer so the entity can be accesed
	*/
	std::shared_ptr<Entity> getEntity();


};

#endif 