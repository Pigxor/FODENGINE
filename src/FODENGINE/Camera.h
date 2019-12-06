#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "engine.h"


class Camera : public Component
{
	glm::mat4 pos;
	glm::mat4 viewMat;
	glm::mat4 projectMat;
	float angle;
	glm::vec3 camPos;
	std::sr1::shared_ptr<rend::RenderTexture> cubemap;
public :
	void cameraInit(float _angle);
	void cameraInit(float _angle, char* _cubemap);
	glm::vec3 getPos();

	glm::mat4 getView();
	glm::mat4 getProjection();
	std::sr1::shared_ptr<rend::RenderTexture> getRenderTarget();
	void Camera::makeTexture(const char * _filePath);
};


#endif