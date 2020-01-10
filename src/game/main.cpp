#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();

	std::shared_ptr<Entity> camEnt = engine->addEntity();
	std::shared_ptr<Transform> camTransf = camEnt->getComponent<Transform>();
	std::shared_ptr<Camera> cam = camEnt->addComponent<Camera>();
	std::shared_ptr<FPContoller> camcont = camEnt->addComponent<FPContoller>();
	cam->cameraInit(60);
	camTransf->setPos(glm::vec3(0, 2, 5));
	camcont->setMovespeed(0.2f);

	std::shared_ptr<Entity> skybox = engine->addEntity();
	std::shared_ptr<Transform> skyTransform = skybox->getComponent<Transform>();
	std::shared_ptr<Renderer> skycomponent = skybox->addComponent<Renderer>();
	std::shared_ptr<Skybox> sb = skybox->addComponent<Skybox>();
	sb->SkyboxInit(cam);
	skycomponent->renderInit("../shaders/skyShader.txt", "../models/Skybox.obj", "../models/road.jpg", true, cam);
	skyTransform->setScale({5,5,5 });
	skyTransform->setRot(0,0, 0);

	std::shared_ptr<Entity> newent = engine->addEntity();
	std::shared_ptr<Transform> newentT = newent->getComponent<Transform>();
	std::shared_ptr<Renderer> newentR = newent->addComponent<Renderer>();
	newentR->renderInit("../shaders/basicShader.txt", "../models/Tibbers.obj", "../models/Tibbers.png", false, cam);
	newentT->setPos({ 0,0,0 });
	newentT->setScale({ 0.01,0.01,0.01 });
	newentT->setRot(0, 0, 0);

	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/Ignite.mmp3"); Ogg Only
	//audio->playSound();

	engine->start();
	
	return 0;
}