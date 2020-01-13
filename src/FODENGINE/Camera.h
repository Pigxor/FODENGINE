#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "engine.h"

class Camera : public Component
{
	int ID;
	int frametimer;
	glm::mat4 posMat;
	glm::mat4 viewMat;
	glm::mat4 projectMat;
	float angle;
	float value = 0;
	glm::vec3 camPos;
	std::sr1::shared_ptr<rend::RenderTexture> cubemap;
public :
	void cameraInit(float _angle);
	glm::vec3 getPos();
	virtual void onUpdate();
	glm::mat4 getView();
	glm::mat4 getProjection();
	void changeCamera(int num);
	void pickCamera(int num);
	void setID(int id);
	void setFtimer(int timer);
};


#endif