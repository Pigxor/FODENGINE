#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Entity> camEnt = engine->addEntity();
	
	std::shared_ptr<Transform> camTransform = camEnt->addComponent<Transform>();
	
	std::shared_ptr<Camera> cam = camEnt->addComponent<Camera>();
	cam->cameraInit(60);
    camTransform->setPos(glm::vec3(0, 0, 5));

	std::shared_ptr<Transform> transform = entity->addComponent<Transform>();
	transform->setPos(glm::vec3(0, -0.5, 0));
	transform->setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	std::shared_ptr<PBR> component = entity->addComponent<PBR>();												//metal roughness ao albedo
	component->renderInit("../shaders/PBRShader.txt", "../models/pbrSphere.obj", "../models/grey.png", false, cam,0.0f, 1.0f, 1.0f, glm::vec3(0.1,0.1,0.1));
	
	//std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
	//component->renderInit("../shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png",false,cam);
	//std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/dixie_horn.ogg");
	//audio->playSound();

	engine->start();
	
	return 0;
}