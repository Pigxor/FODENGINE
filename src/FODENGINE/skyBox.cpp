#include "skyBox.h"



void Skybox::onUpdate()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	cam = getEngine()->getActiveCam();
	transform->setPos(cam->getPos());
	
}
