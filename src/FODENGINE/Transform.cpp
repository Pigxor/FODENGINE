#include "Transform.h"

void Transform::setPos(glm::vec3 pos)
{
	Position = pos;
}

glm::vec3 Transform::getPos()
{
	return Position;
}

void Transform::setRot(glm::vec3 rot)
{
	Rotation = rot;
}

glm::vec3 Transform::getRot()
{
	return Rotation;
}

void Transform::setScale(glm::vec3 scale)
{
	Scale = scale;
}

glm::vec3 Transform::getScale()
{
	return Scale;
}

glm::mat4 Transform::getModel()
{
	return glm::mat4();
}
