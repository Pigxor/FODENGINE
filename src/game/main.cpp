#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
	component->renderInit("../shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png",false);
	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	audio->audioSourceInit("../sounds/dixie_horn.ogg");
	audio->playSound();
	engine->start();
	
	return 0;
}