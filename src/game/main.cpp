#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	/**
	* \brief Makes an instance of the engine
	*/
	std::shared_ptr<Engine> engine = Engine::initialize();
	/**
	* \brief A camera object that has a first person controller and a collision box
	*/
	std::shared_ptr<Camera> cam = engine->addCamera(60);
	std::shared_ptr<FPController> camcont = cam->getEntity()->addComponent<FPController>();
	std::shared_ptr<BoxCollider> cambox = cam->getEntity()->addComponent<BoxCollider>();
	cam->setActive(true);
	cam->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	camcont->setMovespeed(0.2f);
	cambox->boxCollInit(true);
	cambox->setSize(glm::vec3(0.3, 1, 0.3));

	/**	
	* \brief A Camera object that is used as a third person camera
	*/
	std::shared_ptr<Camera> cam2 = engine->addCamera(60);
	cam2->getEntity()->getComponent<Transform>()->setPos(glm::vec3(0, 2, 5));
	cam2->getEntity()->getComponent<Transform>()->setRot(0.0,0.0,0.0);

	/**
	* \brief Large sphere with inverted faces used as the skybox
	* Contains a renderer, transform and skybox component
	*/
	std::shared_ptr<Entity> skybox = engine->addEntity("Skybox");
	std::shared_ptr<Renderer> skycomponent = skybox->addComponent<Renderer>();
	std::shared_ptr<Skybox> sb = skybox->addComponent<Skybox>();
	skycomponent->renderInit("../shaders/skyShader.txt", "../models/Skybox.obj", "../models/road.jpg", true);
	skybox->getComponent<Transform>()->setScale(glm::vec3(2,2,2));
	skybox->getComponent<Transform>()->setRot(0,0, 0);

	/**
	* \brief Object used as the base character for the third person camera
	* Has a renderer,box collder, physics and fpcontroller component
	*/
	std::shared_ptr<Entity> tibbers = engine->addEntity("Tibbers");
	std::shared_ptr<Renderer> tibbersR = tibbers->addComponent<Renderer>();
	std::shared_ptr<BoxCollider> tibbersBC = tibbers->addComponent<BoxCollider>();
	std::shared_ptr<FPController> tibbersC = tibbers->addComponent<FPController>();
	std::shared_ptr<Physics> tibbersP = tibbers->addComponent<Physics>();
	tibbersR->renderInit("../shaders/basicShader.txt", "../models/tibbers/Tibbers.obj", "../models/tibbers/Tibbers.png", false);
	tibbers->getComponent<Transform>()->setPos({ 0,0.5,1 });
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

	/**
	* \brief Object used as the floor of the test level
	*/
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

	/**
	* \brief Object that is animated, model of a bird that flies
	*/
	std::shared_ptr<Entity> valour = engine->addEntity("Valour");
	std::shared_ptr<ModelAnim> valourR = valour->addComponent<ModelAnim>();
	std::shared_ptr<BoxCollider> valourBC = valour->addComponent<BoxCollider>();
	valourR->renderInit("../shaders/basicShader.txt");
	valour->getComponent<Transform>()->setPos({ 0,3,-2 });
	valour->getComponent<Transform>()->setScale({ 0.01,0.01,0.01 });
	valour->getComponent<Transform>()->setRot(0, 0, 0);
	valour->getComponent<Transform>()->setRHeight(1.3f);
	valourBC->boxCollInit(true);
	valourBC->setSize(glm::vec3(0.5, 1, 0.5));
	valourBC->setOffset(glm::vec3(0, 0.5, 0));
	valourBC->setMoveable(false);
	valourR->addTex("../models/Val/valour.png");
	valourR->addMesh("../models/Val/Valn4.obj");
	valourR->addMesh("../models/Val/Valn3.obj");
	valourR->addMesh("../models/Val/Valn2.obj");
	valourR->addMesh("../models/Val/Valn1.obj");
	valourR->addMesh("../models/Val/Val0.obj");
	valourR->addMesh("../models/Val/Val1.obj");
	valourR->addMesh("../models/Val/Val2.obj");
	valourR->addMesh("../models/Val/Val3.obj");
													
	/**
	* \brief Immovable white boxes
	*/
	std::shared_ptr<Entity> whitebox1 = engine->addBox(glm::vec3(2, 1.5, -2),glm::vec3(1,1,1),glm::vec3(0,45,0) , "box1");
	std::shared_ptr<Entity> whitebox2 = engine->addBox(glm::vec3(-2, 1.5, -2),glm::vec3(1,1,1),glm::vec3(0,45,0), "box2");

	/**
	* \brief Line of boxes that can be moved 
	*/
	std::shared_ptr<Entity> whitebox3 = engine->addBox(glm::vec3(-6, 1.5, 8), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), "box3");
	whitebox3->getComponent<BoxCollider>()->setMoveable(true);
	std::shared_ptr<Entity> whitebox4 = engine->addBox(glm::vec3(-3, 1.5, 8), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), "box4");
	whitebox4->getComponent<BoxCollider>()->setMoveable(true);
	std::shared_ptr<Entity> whitebox5 = engine->addBox(glm::vec3(0, 1.5, 8), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0) ,"box5");
	whitebox5->getComponent<BoxCollider>()->setMoveable(true);
	std::shared_ptr<Entity> whitebox6 = engine->addBox(glm::vec3(3, 1.5, 8), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), "box6");
	whitebox6->getComponent<BoxCollider>()->setMoveable(true);
	std::shared_ptr<Entity> whitebox7 = engine->addBox(glm::vec3(6, 1.5, 8), glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), "box7");
	whitebox7->getComponent<BoxCollider>()->setMoveable(true);
	
	/**
	* \brief Gui objecct, circular reticle in the center of the screen 
	*/	
	std::shared_ptr<Entity> gui = engine->addEntity("GUI");	
	std::shared_ptr<GUIRenderer> guiR = gui->addComponent<GUIRenderer>();
	glm::vec4 sizes = glm::vec4((WINDOW_WIDTH/2 - 25), (WINDOW_HEIGHT / 2 - 25), 50, 50);
	guiR->renderInit("../shaders/guiShader.txt", "../models/circle.png");
	guiR->setPosSize(sizes);

	/**
	* \brief Gui object that is a sprite animation
	*/
	std::shared_ptr<Entity> animGUI = engine->addEntity("GUI");
	std::shared_ptr<SpriteAnim> animGUIR = animGUI->addComponent<SpriteAnim>();
	glm::vec4 positioning = glm::vec4(0, WINDOW_HEIGHT-200, 200, 200);
	animGUIR->renderInit("../shaders/guiShader.txt");
	animGUIR->addSprite("../models/sorc/sorc1.png");	
	animGUIR->addSprite("../models/sorc/sorc2.png");	
	animGUIR->addSprite("../models/sorc/sorc3.png");	
	animGUIR->addSprite("../models/sorc/sorc4.png");	
	animGUIR->addSprite("../models/sorc/sorc5.png");	
	animGUIR->addSprite("../models/sorc/sorc6.png");	
	animGUIR->addSprite("../models/sorc/sorc7.png");	
	animGUIR->addSprite("../models/sorc/sorc8.png");	
	animGUIR->addSprite("../models/sorc/sorc9.png");	
	animGUIR->addSprite("../models/sorc/sorc10.png");	
	animGUIR->setPosSize(positioning);

	/**
	* \brief Audio source that plays a song on loop
	*/
	std::shared_ptr<Entity> entity = engine->addEntity("Audio1");
	std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	audio->audioSourceInit("../sounds/ignite.ogg");

	/**
	* \brief Initiates the engine loop so that all the updates happen
	*/
	engine->start();
	
	return 0;
}