#include "Camera.h"

glm::mat4 Camera::getView()
{
	return viewMat;
}

glm::mat4 Camera::getProjection()
{
	return projectMat;
}
