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

class Component
{
	friend Entity;
protected: 
	std::weak_ptr<Entity> entity;
	std::weak_ptr<Engine> engine;
	virtual void onCreate();
	virtual void onStart();
	virtual void onUpdate();
	virtual void onDisplay();
	//onInit();
	bool active;
public:
	void setActive(bool Active);
	bool getActive();
	const char* name;
	std::shared_ptr<Engine> getEngine();
	std::shared_ptr<Entity> getEntity();


};

#endif 