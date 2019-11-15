#include <iostream>
#include <fodengine/engine.h>
#include <memory>



int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Triangle> component = entity->addComponent<Triangle>();
	engine->start();

	
	return 0;
}