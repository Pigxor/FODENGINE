#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "engine.h"
/**
* \brief Component that adds gravity to an object
* Also allows for simple parabolic motion
*/
class Physics : public Component
{
	bool kinematic; ///< Bool that controls if the entity experiences physics
	glm::vec3 velocity; ///< Velocity of the entity
	glm::vec3 v; ///< Velocity with gravity
	float grav = -9.81; ///< Value for gravity
public:
	Physics();
	/**
	* \brief Update loop, Applies gravity to the entity
	*/
	void onUpdate();
	/**
	* \brief Sets the velocity value
	*/
	void setVelocity(glm::vec3 vel);
	/**
	* \brief Sets gravity value
	*/
	void setGrav(float Grav);
	/**
	* \brief Adds velocity to the saved velocity value
	*/
	void addVelocity(glm::vec3 vel);
	/**
	* \brief Returns the velocity with gravity applied
	*/
	glm::vec3 getV();
	/**
	* \brief Returns the velocity of the entity
	*/
	glm::vec3 getVelocity();
	/**
	* \brief Checks if entity is kinematic
	*/
	bool getKinematic();
	/**
	* \brief Sets kinematic bool
	*/
	void setKinematic(bool kine);
};

#endif // !_PHYSICS_H_
