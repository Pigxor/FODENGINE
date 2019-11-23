#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "component.h"


class Camera : public Component
{
	glm::mat4 pos;
	glm::mat4 viewMat;
	glm::mat4 projectMat;
	float angle;
public :
	void cameraInit(float _angle);


	glm::mat4 getView();
	glm::mat4 getProjection();
};


#endif