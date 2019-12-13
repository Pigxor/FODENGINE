#include "Camera.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

void Camera::cameraInit(float _angle)
{
	angle = _angle;
	posMat = glm::mat4(1.0f);
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
}


glm::vec3 Camera::getPos()
{
	return camPos;
}

void Camera::onUpdate()
{

	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
	transform->addRot(0, -0.008, 0);
	//transform->addPos(glm::vec3(0, 0, 0.08));
}

glm::mat4 Camera::getView()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	viewMat = transform->getModel();
	return glm::inverse(viewMat);
}

glm::mat4 Camera::getProjection()
{
	projectMat = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 1000.0f);
	return projectMat;
}

std::sr1::shared_ptr<rend::RenderTexture> Camera::getRenderTarget()
{
	return cubemap;
}

void Camera::makeRenderTexture()
{
	
	std::sr1::shared_ptr<Engine> eng = getCore();
	std::sr1::shared_ptr<rend::RenderTexture> tex = eng->context->createRenderTexture();
	tex->setSize(512, 512);
	cubemap = tex;
}