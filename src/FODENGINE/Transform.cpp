#include "Transform.h"
#include "Camera.h"

Transform::Transform()
{
	position = glm::vec3(0, 0, 0);
	rotationY = 0;
	rotationX = 0;
	rotationZ = 0;
	scale = glm::vec3(1.0f,1.0f,1.0f);
	model = glm::mat4(1.0f);	
	relativeHeight = scale.y;
}

void Transform::setPos(glm::vec3 pos)
{
	position = pos;
}

void Transform::addPos(glm::vec3 pos)
{
	position += pos;
}

glm::vec3 Transform::getPos()
{
	return position;
}

void Transform::setRot(float rotX, float rotY, float rotZ)
{
	rotationY = rotY;
	rotationX = rotX;			
	rotationZ = rotZ;
}

void Transform::addRot(float rotX, float rotY, float rotZ)
{
	rotationY += rotY;
	rotationX += rotX;
	rotationZ += rotZ;
}

float Transform::getRotY()
{
	return rotationY;
}
float Transform::getRotX()
{
	return rotationX;
}

float Transform::getRotZ()
{
	return rotationZ;
}

void Transform::setRHeight(float height)
{
	relativeHeight = height;
}

float Transform::getRHeight()
{
	return relativeHeight;
}

void Transform::setScale(glm::vec3 _scale)
{
	scale = _scale;
}

glm::vec3 Transform::getScale()
{
	return scale;
}

glm::mat4 Transform::getModel()
{
	model = glm::mat4(1.0f);
	
	model = glm::translate(model, position);
	model = glm::rotate(model, glm::radians(rotationY), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(rotationX), glm::vec3(1, 0, 0));
	model = glm::translate(model, -position);
	model = glm::translate(model, position);
	model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0, 0, 1));
	model = glm::rotate(model, glm::radians(0.0f), glm::vec3(1, 0, 0));
	//model = glm::translate(model, position);
	model = glm::scale(model, scale);

	return model;
}
