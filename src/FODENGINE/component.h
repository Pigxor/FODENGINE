#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <iostream>
class Entity;
class Engine;

class Component
{
	friend Entity;

	std::weak_ptr<Entity> entity;
	virtual void onCreate();
	virtual void onStart();
	virtual void onUpdate();
	virtual void onDisplay();
public:

	std::shared_ptr<Engine> getCore();

};

#endif // !_ENGINE_H