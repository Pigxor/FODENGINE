#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Entity> camEnt = engine->addEntity();
	
	std::shared_ptr<Transform> camTransform = camEnt->addComponent<Transform>();
	camTransform->setPos(glm::vec3(0, 0, 50));
	std::shared_ptr<Camera> cam = camEnt->addComponent<Camera>();
	cam->cameraInit(60);
	std::shared_ptr<Transform> transform = entity->addComponent<Transform>();
	transform->setRot(10.f, 0, 0);
	transform->setPos(glm::vec3(0, -0.5, -3));
	transform->setScale(glm::vec3(10.0f, 10.0f, 10.0f));
	std::shared_ptr<PBR> component = entity->addComponent<PBR>();
	component->renderInit("../shaders/PBRShader.txt", "../models/pbrSphere.obj", "../models/red.png", false, cam, 0.0f, 0.0f, 0.0f, glm::vec3(0.0f));
	//std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
	//component->renderInit("../shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png",false,cam);
	
	//std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/dixie_horn.ogg");
	//audio->playSound();
	engine->start();
	
	return 0;
}