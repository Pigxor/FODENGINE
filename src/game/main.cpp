#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <fodengine/engine.h>
#include <memory>

int main()
{
	std::shared_ptr<Engine> engine = Engine::initialize();
	std::shared_ptr<Entity> entity = engine->addEntity();
	std::shared_ptr<Entity> camEnt = engine->addEntity();
	std::shared_ptr<Transform> camTransform = camEnt->addComponent<Transform>();
	std::shared_ptr<Camera> camRT = camEnt->addComponent<Camera>();
	camRT->cameraInit(60);
	camRT->makeRenderTexture();
    camTransform->setPos(glm::vec3(0, 1, 5));
	
	std::shared_ptr<Entity> camEnt2 = engine->addEntity();
	std::shared_ptr<Transform> camTransform2 = camEnt2->addComponent<Transform>();
	std::shared_ptr<Camera> cam = camEnt2->addComponent<Camera>();
	cam->cameraInit(60);
	camTransform2->setPos(glm::vec3(0, 1, 5));
	//six cameras into a vector for cubemap different rotations etc.
	std::shared_ptr<Entity> skybox = engine->addEntity();
	std::shared_ptr<Transform> skyTransform = skybox->addComponent<Transform>();
	std::shared_ptr<Renderer> skycomponent = skybox->addComponent<Renderer>();
	skycomponent->renderInit("../shaders/basicShader.txt", "../models/Skybox.obj", "../models/skycloud.jpg", false, cam);
	skyTransform->setPos({ 0,0, 0 });	
	skyTransform->setScale({ 0.5,0.5,0.5 });
	skyTransform->setRot(0, 0, 0);

	//Rusty Ball
	std::shared_ptr<Transform> transform = entity->addComponent<Transform>();	
	transform->setPos(glm::vec3(-1.5, 0, 1));
	transform->setScale(glm::vec3(1,1,1));
	std::shared_ptr<PBR> component = entity->addComponent<PBR>();							//originalTex					                                                     //metal roughness ao albedo normal
	component->renderInit("../shaders/IBLShader.txt", "../models/pbrSphere.obj", "../models/white.png", skyTransform, cam,camRT, "../models/metallicMap.png", "../models/roughnessMap.png", "../models/white.png", "../models/albedoMap.png","../models/normalMap.png", "../models/skycloudIMap.jpg");
	//White Ball
	std::shared_ptr<Entity> entity2 = engine->addEntity();
	std::shared_ptr<Transform> transform2 = entity2->addComponent<Transform>();
	transform2->setPos(glm::vec3(1.5, 0, 1));
	transform2->setScale(glm::vec3(1, 1, 1));
	transform2->setRot(0, 0, 0);
	std::shared_ptr<PBR> component2 = entity2->addComponent<PBR>();							//originalTex					              //metal               roughness                   ao                  albedo                       normal
	component2->renderInit("../shaders/IBLShader.txt", "../models/pbrSphere.obj", "../models/white.png", skyTransform, cam, camRT, "../models/white.png", "../models/white.png", "../models/white.png", "../models/white.png", "../models/white.png", "../models/skycloudIMap.jpg");


	//std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/dixie_horn.ogg");
	//audio->playSound();

	engine->start();
	
	return 0;
}