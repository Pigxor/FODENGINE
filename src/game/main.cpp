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
	cam->setActive(true);
	cam->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	camcont->setMovespeed(0.2f);
	cambox->boxCollInit(true);
	cambox->setSize(glm::vec3(1, 1, 1));

	std::shared_ptr<Camera> cam2 = engine->addCamera(60);
	std::shared_ptr<FPContoller> camcont2 = cam2->getEntity()->addComponent<FPContoller>();
	std::shared_ptr<BoxCollider> cambox2 = cam2->getEntity()->addComponent<BoxCollider>();
	cam2->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	camcont2->setMovespeed(0.2f);
	cambox2->boxCollInit(false);
	cambox2->setSize(glm::vec3(1, 1, 1));

	std::shared_ptr<Camera> cam3 = engine->addCamera(60);
	std::shared_ptr<FPContoller> camcont3 = cam3->getEntity()->addComponent<FPContoller>();
	std::shared_ptr<BoxCollider> cambox3 = cam3->getEntity()->addComponent<BoxCollider>();
	cam3->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	camcont3->setMovespeed(0.2f);
	cambox3->boxCollInit(false);
	cambox3->setSize(glm::vec3(1, 1, 1));

	std::shared_ptr<Entity> skybox = engine->addEntity("Skybox");
	std::shared_ptr<Transform> skyTransform = skybox->getComponent<Transform>();
	std::shared_ptr<Renderer> skycomponent = skybox->addComponent<Renderer>();
	std::shared_ptr<Skybox> sb = skybox->addComponent<Skybox>();
	skycomponent->renderInit("../shaders/skyShader.txt", "../models/Skybox.obj", "../models/road.jpg", true);
	skyTransform->setScale({5,5,5 });
	skyTransform->setRot(0,0, 0);

	std::shared_ptr<Entity> newent = engine->addEntity("Tibbers");
	std::shared_ptr<Transform> newentT = newent->getComponent<Transform>();
	std::shared_ptr<Renderer> newentR = newent->addComponent<Renderer>();
	std::shared_ptr<BoxCollider> newentBC = newent->addComponent<BoxCollider>();
	newentR->renderInit("../shaders/basicShader.txt", "../models/Tibbers.obj", "../models/Tibbers.png", false);
	newentT->setPos({ 0,0,0 });
	newentT->setScale({ 0.01,0.01,0.01 });
	newentT->setRot(0, 0, 0);
	newentBC->boxCollInit(true);
	newentBC->setSize(glm::vec3(0.1, 0.1, 0.1));
	newentBC->setOffset(glm::vec3(0, 1, 0));
	newentBC->setMoveable(false);

	std::shared_ptr<Entity> gui = engine->addEntity("GUI");	
	std::shared_ptr<GUIRenderer> guiR = newent->addComponent<GUIRenderer>();
	glm::vec4 sizes = glm::vec4(0, 0, 100, 100);
	guiR->renderInit("../shaders/guiShader.txt", "../models/reticle.png");
	guiR->setPosSize(sizes);

	std::shared_ptr<Entity> entity = engine->addEntity("Audio1");
	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/Ignite.mmp3"); Ogg Only
	//audio->playSound();

	engine->start();
	
	return 0;
}