#include "component.h"

void Component::onCreate()
{
}

void Component::onStart()
{
}

void Component::onUpdate()
{
}

void Component::onDisplay()
{
}

std::shared_ptr<Engine> Component::getCore()
{
	return engine.lock();
}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}
