#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "engine.h"
#include <memory>
#include <vector>
#include <iostream>


class Engine;
class Component;
class Transform;

/**
* \brief Primary object that Components are attatched to
*/
class Entity
{	
	friend Engine;
	
	std::weak_ptr<Engine> engine; ///< Weak pointer to the engine
	std::weak_ptr<Entity> self; ///< Weak pointer to itself
	std::shared_ptr<Transform> transf; ///< Weak pointer to its attatched transform function
	std::vector<std::shared_ptr<Component>> components; ///< Vector of attatched components
	/**
	* \brief Update funtion that runs through all the update functions of each component attached to this entity
	*/
	virtual void Update();
	/**
	* \brief Display funtion that runs through all the dispaly functions of each component attached to this entity
	*/
	virtual void Display();
	bool floor = false; ///< Bool to check if object is the floor

public:
	const char* name; ///< Name of entity - equivalent to tags in Unity
	/**
	* \brief Returns a specific component
	*/
	template<class T>
	std::shared_ptr<T> getComponent()
	{
		std::shared_ptr<T> rtn;
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			rtn = std::dynamic_pointer_cast<T>(*it);

			if (rtn)
			{
				return rtn;
			}

		}
	}
	/**
	* \brief Searches entity for a specific component
	*/
	template<class T>
	bool checkComponent()
	{
		std::shared_ptr<T> rtn;
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			rtn = std::dynamic_pointer_cast<T>(*it);

			if (rtn)
			{
				return true;
			}

		}
		return false;
	}
	/**
	* \brief Returns a pointer ot the engine
	*/
	std::shared_ptr<Engine> getEngine(std::shared_ptr<Engine> _engine);
	/**
	* \brief Various versions of adding a component to this entity
	*/
	template <class T>
	std::shared_ptr<T> addComponent() {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		rtn->name = name;
		return rtn;
	}
	template <class T, class U>
	std::shared_ptr<T> addComponent(U u) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		rtn->name = name;
		return rtn;
	}
	template <class T, class U, class V>
	std::shared_ptr<T> addComponent(U u, V v) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		rtn->name = name;
		return rtn;
	}
	template <class T, class U, class V, class W>
	std::shared_ptr<T> addComponent(U u, V v, W w) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		rtn->name = name;
		return rtn;
	}
	/**
	* \brief Checks if this entity is the floor
	*/
	bool getFloor();
	/**
	* \brief Sets the floor bool
	*/
	void setFloor(bool Floor);
};

#endif