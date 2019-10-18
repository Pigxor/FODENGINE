#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <memory>
#include <vector>
#include <iostream>
#include "component.h"

class Engine;
class Component;

class Entity
{	
	friend Engine;

	std::weak_ptr<Engine> engine;
	std::vector<std::shared_ptr<Component>> components;
	virtual void Update();
	virtual void Display();

	//glm::vec3 Position;
	//glm::mat4 Rotation;
public:
	//void setPos(glm::vec3 pos);
	//glm::vec3 getPos();
	//void setRot(glm::mat4 rot);
	//glm::mat4 getRot();



	std::shared_ptr<Engine> getCore();
	template <class T>
	std::shared_ptr<T> addComponent() {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}
	template <class T, class U>
	std::shared_ptr<T> addComponent(U u) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}
	template <class T, class U, class V>
	std::shared_ptr<T> addComponent(U u, V v) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}
	template <class T, class U, class V, class W>
	std::shared_ptr<T> addComponent(U u, V v, W w) {
		std::shared_ptr<T>rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}
};

#endif