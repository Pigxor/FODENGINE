#include "Camera.h"


#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

void Camera::cameraInit(float _angle)
{
	angle = _angle;
	pos = glm::mat4(1.0f);
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
}

glm::vec3 Camera::getPos()
{
	return camPos;
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
	projectMat = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
	return projectMat;
}
