#ifndef _FPCONTROLLER_H_
#define _FPCONTROLLER_H_

#include "engine.h"

class FPContoller : public Component
{
	glm::vec3 fwd;
	glm::vec3 right;
	glm::vec3 up;

	glm::vec3 pos;

	float movespeed = 0.5f;
	float rotspeed = 1.5f;
	float angleX;
	float angleY;

	int mouseX;
	int mouseY;
	std::shared_ptr<Camera> cam;
	glm::vec3 offset;
	bool cursorLock = true;
	bool firstperson = true;
public:

	FPContoller();
	void FPContollerInit(std::shared_ptr<Camera> Cam, glm::vec3 Offset);
	virtual void onUpdate();
	void setMovespeed(float movs);

};


#endif