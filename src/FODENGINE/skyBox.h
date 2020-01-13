#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include "engine.h"

class Skybox : public Component
{
	std::shared_ptr<Camera> cam;
public:
	virtual void onUpdate();

};

#endif