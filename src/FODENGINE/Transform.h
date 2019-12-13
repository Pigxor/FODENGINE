
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "component.h"

class Camera;

class Transform : public Component
{

	glm::vec3 position;
	float rotationY;
	float rotationX;
	float rotationZ;
	glm::vec3 scale;
	glm::mat4 model;

public:

	Transform();
	void setPos(glm::vec3 pos);
	void addPos(glm::vec3 pos);
	glm::vec3 getPos();
	void setRot(float rotX, float rotY, float rotZ);
	void addRot(float rotX, float rotY, float rotZ);
	float getRot();
	void setScale(glm::vec3 _scale);
	glm::vec3 getScale();
	glm::mat4 getModel(glm::vec3 cam);
	glm::mat4 getModel();
};

#endif