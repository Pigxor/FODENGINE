#ifndef _BOX_COLLIDER_H_
#define _BOX_COLLIDER_H_

#include "engine.h"

/**
* \brief Component provides a box collider and checks for collision
*/
class BoxCollider : public Component
{
	glm::vec3 size; ///< Size of the collider
	glm::vec3 offset; ///< Any offset needed for the collider
	glm::vec3 lastPos; ///< Previous position of the collider

	bool moveable; ///< Bool that controls if the collider can be moved by another object
	bool landed = false; ///< Bool that checks if the collider has landed on the floor
	bool colls; ///< Bool that checks if any collisions have taken place this frame
	/**
	* \brief Update loop, Checks for all collisions
	*/
	void onUpdate();
	/**
	* \brief UNUSED - For mesh collision
	*/
	void staticMeshCollide();
	/**
	* \brief Checks the collisions and handles the responses
	*/
	void boxCollide();
	/**
	* \brief Checks if This object is colliding with another
	*/
	bool isColliding(glm::vec3 pos, glm::vec3 Size);
	/**
	* \brief Gets the collision response to be applied to the current object
	*/
	glm::vec3 getCollResponse(glm::vec3 pos, glm::vec3 size);
	/**
	* \brief Vector of object sthe current object is colliding with
	*/
	std::vector<std::shared_ptr<Entity>> colliding;
public:
	/**
	* \brief Basic Initialisation fo the box collider, including if its active
	*/
	void boxCollInit(bool Active);
	/**
	* \brief Sets the offset of the collision box
	*/
	void setOffset(glm::vec3 Offset);
	/**
	* \brief Sets the size of the collision box
	*/
	void setSize(glm::vec3 Size);
	/**
	* \brief Returns the size fo the collision box
	*/
	glm::vec3 getSize();
	/**
	* \brief Collision checck to be called when you want to check specific collisions
	*/
	bool checkColliding(glm::vec3 pos, glm::vec3 Size);
	/**
	* \brief Checks if the collider has landed
	*/
	bool getLanded();
	/**
	* \brief Sets the collider landed bool
	*/
	void setLanded(bool land);
	/**
	* \brief Sets the collider moveable bool
	*/
	void setMoveable(bool Active);
	/**
	* \brief Checks if the collider is moveable
	*/
	bool getMoveable();
};

#endif