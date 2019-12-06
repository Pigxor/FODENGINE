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
	cam->cameraInit(60, "../Summi_Pool/Summi_Pool_preview.jpg");
    camTransform->setPos(glm::vec3(0, 0, 5));
	
	std::shared_ptr<Entity> camEnt2 = engine->addEntity();
	std::shared_ptr<Transform> camTransform2 = camEnt2->addComponent<Transform>();
	std::shared_ptr<Camera> cam2 = camEnt2->addComponent<Camera>();
	cam2->cameraInit(60);
	camTransform2->setPos(glm::vec3(0, 0, 5));
	//six cameras into a vector for cubemap different rotations etc.
	std::shared_ptr<Transform> transform = entity->addComponent<Transform>();
	transform->setPos(glm::vec3(-2, -0.5, 0));
	transform->setScale(glm::vec3(1.0f, 1.0f, 1.0f));
	std::shared_ptr<PBR> component = entity->addComponent<PBR>();							//originalTex					                                                     //metal roughness ao albedo normal
	component->renderInit("../shaders/PBRShader.txt", "../models/pbrSphere.obj", "../models/albedoMap.png", false, cam2,cam, "../models/metallicMap.png", "../models/roughnessMap.png", "../models/grey.png", "../models/albedoMap.png","../models/normalMap.png");
	
	std::shared_ptr<Entity> cubeEntity = engine->addEntity();
	std::shared_ptr<Transform> cubeTransform = cubeEntity->addComponent<Transform>();
	std::shared_ptr<PBR> cubeComponent = cubeEntity->addComponent<PBR>();
	cubeComponent->renderInit("../shaders/PBRShader.txt", "../models/cube.obj", "../Summi_Pool/Summi_Pool_preview.jpg", false, cam2,cam, "../models/grey.png", "../models/grey.png", "../models/grey.png", "../models/grey.png", "../models/grey.png");
	cubeTransform->setPos(glm::vec3(2, 0, 0));
	cubeTransform->setRot(0.0,45,45);
	cubeTransform->setScale(glm::vec3(1.0f, 1.0f, 1.0f));

	//component->cubemapInit("../Summi_Pool/Summi_Pool_3k.hdr", "../shaders/cubemapShader.txt","../models/cube.obj");
	//std::shared_ptr<Renderer> component = entity->addComponent<Renderer>();
	//component->renderInit("../shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png",false,cam);
	//std::shared_ptr<audioSource> audio = entity->addComponent<audioSource>();
	//audio->audioSourceInit("../sounds/dixie_horn.ogg");
	//audio->playSound();

	engine->start();
	
	return 0;
}