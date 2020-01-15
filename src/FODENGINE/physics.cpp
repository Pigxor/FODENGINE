#include "physics.h"

Physics::Physics()
{
	kinematic = true;
}

void Physics::onUpdate()
{
	std::shared_ptr<Entity> ent = getEntity();
	std::shared_ptr<Engine> eng = getEngine();
	if (kinematic == true)
	{
	
		glm::vec3 pos = ent->getComponent<Transform>()->getPos();
		glm::vec3 a = glm::vec3(0.0, grav, 0.0);
		v = velocity + (a * (eng->getDeltaT() / 50));
		setVelocity(v);
		if (ent->getComponent<BoxCollider>()->getLanded())
		{
			setVelocity(glm::vec3(v.x, 0.0f, v.z));
		}
		if (!ent->getComponent<BoxCollider>()->getLanded())
		{
			ent->getComponent<Transform>()->addPos(v); 
		}

	}
	
}

void Physics::setVelocity(glm::vec3 vel)
{
	velocity = vel;
}

void Physics::setGrav(float Grav)
{
	grav = Grav;
}


void Physics::addVelocity(glm::vec3 vel)
{
	velocity += vel;
}

glm::vec3 Physics::getV()
{
	return glm::vec3();
}

glm::vec3 Physics::getVelocity()
{
	return velocity;
}


bool Physics::getKinematic()
{
	return kinematic;
}

void Physics::setKinematic(bool kine)
{
	kinematic = kine;
}

