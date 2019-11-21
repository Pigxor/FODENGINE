#include <iostream>
#include <fodengine/engine.h>
#include <memory>



int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
	component->renderInit("../shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png",false);
	engine->start();

	
	return 0;
}