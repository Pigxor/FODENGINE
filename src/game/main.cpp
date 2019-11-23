#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Entity> camEnt = engine->addEntity();
	std::shared_ptr<Camera> cam = camEnt->addComponent<Camera>();
	cam->cameraInit(60);
	std::shared_ptr<Transform> transform = entity->addComponent<Transform>();
	transform->setRot(10.f, 0, 0);
	std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
	component->renderInit("../shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png",false,cam);
	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	audio->audioSourceInit("../sounds/dixie_horn.ogg");
	audio->playSound();
	engine->start();
	
	return 0;
}