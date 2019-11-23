#include "Camera.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

void Camera::cameraInit(float _angle)
{
	angle = _angle;
	pos = glm::mat4(1.0f);
}

glm::mat4 Camera::getView()
{
	return viewMat;
}

glm::mat4 Camera::getProjection()
{
	projectMat = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
	return projectMat;
}
