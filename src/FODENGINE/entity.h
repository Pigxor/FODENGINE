#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>
#include <vector>
#include <iostream>
#include <rend/rend.h>

class Engine;
class Component;

class Entity
{	
	friend Engine;

	std::weak_ptr<Engine> engine;
	std::weak_ptr<Entity> self;
	std::vector<std::shared_ptr<Component>> components;
	virtual void Update();
	virtual void Display();

public:
	
	template<class T>
	std::shared_ptr<T> getComponent()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
		}
		if (rtn)
		{
			return rtn;
		}
		else
		{
			throw rend::Exception("Failed To Find Component Of Specified Type");
		}
	}

	std::shared_ptr<Engine> getEngine(std::shared_ptr<Engine> _engine);

	template <class T>
	std::shared_ptr<T> addComponent() {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		return rtn;
	}
	template <class T, class U>
	std::shared_ptr<T> addComponent(U u) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		return rtn;
	}
	template <class T, class U, class V>
	std::shared_ptr<T> addComponent(U u, V v) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		engine->context->createShader();
		return rtn;
	}
	template <class T, class U, class V, class W>
	std::shared_ptr<T> addComponent(U u, V v, W w) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		rtn->entity = self;
		rtn->engine = engine;
		return rtn;
	}
};

#endif