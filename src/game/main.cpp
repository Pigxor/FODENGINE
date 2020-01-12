#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();

	std::shared_ptr<Entity> camEnt = engine->addEntity("Camera1");
	std::shared_ptr<Transform> camTransf = camEnt->getComponent<Transform>();
	std::shared_ptr<Camera> cam = camEnt->addComponent<Camera>();
	std::shared_ptr<FPContoller> camcont = camEnt->addComponent<FPContoller>();
	std::shared_ptr<BoxCollider> cambox = camEnt->addComponent<BoxCollider>();
	cam->cameraInit(60);
	camTransf->setPos(glm::vec3(0, 2, 5));
	camcont->setMovespeed(0.2f);
	cambox->boxCollInit();
	cambox->setSize(glm::vec3(1, 1, 1));

	std::shared_ptr<Entity> skybox = engine->addEntity("Skybox");
	std::shared_ptr<Transform> skyTransform = skybox->getComponent<Transform>();
	std::shared_ptr<Renderer> skycomponent = skybox->addComponent<Renderer>();
	std::shared_ptr<Skybox> sb = skybox->addComponent<Skybox>();
	sb->SkyboxInit(cam);
	skycomponent->renderInit("../shaders/skyShader.txt", "../models/Skybox.obj", "../models/road.jpg", true, cam);
	skyTransform->setScale({5,5,5 });
	skyTransform->setRot(0,0, 0);

	std::shared_ptr<Entity> newent = engine->addEntity("Tibbers");
	std::shared_ptr<Transform> newentT = newent->getComponent<Transform>();
	std::shared_ptr<Renderer> newentR = newent->addComponent<Renderer>();
	std::shared_ptr<BoxCollider> newentBC = newent->addComponent<BoxCollider>();
	newentR->renderInit("../shaders/basicShader.txt", "../models/Tibbers.obj", "../models/Tibbers.png", false, cam);
	newentT->setPos({ 0,0,0 });
	newentT->setScale({ 0.01,0.01,0.01 });
	newentT->setRot(0, 0, 0);
	newentBC->boxCollInit();
	newentBC->setSize(glm::vec3(0.1, 0.1, 0.1));
	newentBC->setOffset(glm::vec3(0, 1, 0));

	std::shared_ptr<Entity> entity = engine->addEntity("Audio1");
	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/Ignite.mmp3"); Ogg Only
	//audio->playSound();

	engine->start();
	
	return 0;
}