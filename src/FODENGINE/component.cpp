#include "component.h"

void Component::onCreate()
{
}

void Component::onStart()
{
}

void Component::onUpdate()
{
	std::cout << "Component Update Finish" << std::endl;
}

void Component::onDisplay()
{
}

std::shared_ptr<Engine> Component::getCore()
{
	return std::shared_ptr<Engine>();
}
