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
	float rotspeed = 1.0f;
	float angleX;
	float angleY;

	int mouseX;
	int mouseY;

	bool cursorLock = true;
public:

	FPContoller();
	virtual void onUpdate();
	void setMovespeed(float movs);

};


#endif