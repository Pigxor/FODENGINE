#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "component.h"


class Camera : public Component
{
	glm::mat4 viewMat;
	glm::mat4 projectMat;

public :
	
	glm::mat4 getView();
	glm::mat4 getProjection();
};


#endif