#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "engine.h"
#include <memory>
#include <vector>
#include <iostream>


class Engine;
class Component;
class Transform;

class Entity
{	
	friend Engine;
	
	std::weak_ptr<Engine> engine;
	std::weak_ptr<Entity> self;
	std::shared_ptr<Transform> transf;
	std::vector<std::shared_ptr<Component>> components;
	virtual void Update();
	virtual void Display();
	bool floor = false;

public:
	const char* name;
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
	std::shared_ptr<Engine> getEngine(std::shared_ptr<Engine> _engine);

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

	bool getFloor();
	void setFloor(bool Floor);
};

#endif