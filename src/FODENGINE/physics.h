#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "engine.h"

class Physics : public Component
{
	bool kinematic;

	glm::vec3 velocity;
	glm::vec3 v;
	float grav = -9.81;
public:
	Physics();
	void onUpdate();
	void setVelocity(glm::vec3 vel);
	void setGrav(float Grav);
	void addVelocity(glm::vec3 vel);
	glm::vec3 getV();
	glm::vec3 getVelocity();

	bool getKinematic();
	void setKinematic(bool kine);
};

#endif // !_PHYSICS_H_
