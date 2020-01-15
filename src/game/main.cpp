#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Camera> cam = engine->addCamera(60);
	std::shared_ptr<FPContoller> camcont = cam->getEntity()->addComponent<FPContoller>();
	std::shared_ptr<BoxCollider> cambox = cam->getEntity()->addComponent<BoxCollider>();
	std::shared_ptr<Physics> camP = cam->getEntity()->addComponent<Physics>();
	cam->setActive(true);
	cam->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	camcont->setMovespeed(0.2f);
	cambox->boxCollInit(true);
	cambox->setSize(glm::vec3(0.3, 1, 0.3));


	std::shared_ptr<Camera> cam2 = engine->addCamera(60);
//	std::shared_ptr<FPContoller> camcont2 = cam2->getEntity()->addComponent<FPContoller>();
	//std::shared_ptr<BoxCollider> cambox2 = cam2->getEntity()->addComponent<BoxCollider>();
	cam2->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	cam2->getEntity()->getComponent<Transform>()->setRot(0.0,0.0,0.0);
	//camcont2->setMovespeed(0.2f);
	//cambox2->boxCollInit(false);
//	cambox2->setSize(glm::vec3(1, 1, 1));
	/*
	std::shared_ptr<Camera> cam3 = engine->addCamera(60);
	std::shared_ptr<FPContoller> camcont3 = cam3->getEntity()->addComponent<FPContoller>();
	std::shared_ptr<BoxCollider> cambox3 = cam3->getEntity()->addComponent<BoxCollider>();
	cam3->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	camcont3->setMovespeed(0.2f);
	cambox3->boxCollInit(false);
	cambox3->setSize(glm::vec3(1, 1, 1));*/

	std::shared_ptr<Entity> skybox = engine->addEntity("Skybox");
	std::shared_ptr<Renderer> skycomponent = skybox->addComponent<Renderer>();
	std::shared_ptr<Skybox> sb = skybox->addComponent<Skybox>();
	skycomponent->renderInit("../shaders/skyShader.txt", "../models/Skybox.obj", "../models/road.jpg", true);
	skybox->getComponent<Transform>()->setScale(glm::vec3(2,2,2));
	skybox->getComponent<Transform>()->setRot(0,0, 0);

	std::shared_ptr<Entity> tibbers = engine->addEntity("Tibbers");
	std::shared_ptr<Renderer> tibbersR = tibbers->addComponent<Renderer>();
	std::shared_ptr<BoxCollider> tibbersBC = tibbers->addComponent<BoxCollider>();
	std::shared_ptr<FPContoller> tibbersC = tibbers->addComponent<FPContoller>();
	tibbersR->renderInit("../shaders/basicShader.txt", "../models/Tibbers.obj", "../models/Tibbers.png", false);
	tibbers->getComponent<Transform>()->setPos({ 0,0.5,0 });
	tibbers->getComponent<Transform>()->setScale({ 0.01,0.01,0.01 });
	tibbers->getComponent<Transform>()->setRot(0, 180, 0);
	tibbers->getComponent<Transform>()->setRHeight(1.3f);
	tibbersBC->boxCollInit(true);
	tibbersBC->setSize(glm::vec3(0.5, 1, 0.5));
	tibbersBC->setOffset(glm::vec3(0, 0.5, 0));
	tibbersBC->setMoveable(false);
	tibbersC->FPContollerInit(cam2, glm::vec3(0, -3, -3));
	tibbersC->setActive(false);
	tibbersC->setMovespeed(0.2f);

	std::shared_ptr<Entity> floor = engine->addEntity("Floor");
	floor->setFloor(true);
	std::shared_ptr<Renderer> floorR = floor->addComponent<Renderer>();
	std::shared_ptr<BoxCollider> floorBC = floor->addComponent<BoxCollider>();
	floorR->renderInit("../shaders/basicShader.txt", "../models/cube.obj", "../models/grey.png", false);
	floor->getComponent<Transform>()->setPos({ 0,0,0 });
	floor->getComponent<Transform>()->setScale({ 50,0.5,50 });
	floor->getComponent<Transform>()->setRot(0, 0, 0);
	floor->getComponent<Transform>()->setRHeight(0.1);
	floorBC->boxCollInit(true);
	floorBC->setSize(glm::vec3(50, 1, 50));
	floorBC->setOffset(glm::vec3(0, 0, 0));
	floorBC->setMoveable(false);
													
	std::shared_ptr<Entity> whitebox1 = engine->addBox(glm::vec3(2, 1.5, -2),glm::vec3(1,1,1),glm::vec3(0,45,0));
	std::shared_ptr<Entity> whitebox2 = engine->addBox(glm::vec3(-2, 1.5, -2),glm::vec3(1,1,1),glm::vec3(0,45,0));
	
	std::shared_ptr<Entity> gui = engine->addEntity("GUI");	
	std::shared_ptr<GUIRenderer> guiR = tibbers->addComponent<GUIRenderer>();
	glm::vec4 sizes = glm::vec4((WINDOW_WIDTH/2 - 25), (WINDOW_HEIGHT / 2 - 25), 50, 50); //makes the gui central
	guiR->renderInit("../shaders/guiShader.txt", "../models/circle.png");
	guiR->setPosSize(sizes);

	std::shared_ptr<Entity> entity = engine->addEntity("Audio1");
	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/Ignite.mp3"); Ogg Only
	//audio->playSound();

	engine->start();
	
	return 0;
}