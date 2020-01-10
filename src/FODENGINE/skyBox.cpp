#include "skyBox.h"

void Skybox::SkyboxInit(std::shared_ptr<Camera> cam1)
{
	cam = cam1;
}

void Skybox::onUpdate()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();

	transform->setPos(cam->getPos());
	
}
