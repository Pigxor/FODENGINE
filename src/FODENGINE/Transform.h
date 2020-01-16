
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "component.h"

class Camera;

/**
* \brief Component that decides the position, rotation and scale of an entity
*/
class Transform : public Component
{

	glm::vec3 position; ///< Position of the entity within the world  
	float rotationY; ///< Rotation in the Y axis
	float rotationX; ///< Rotation in the X axis
	float rotationZ; ///< Rotation in the Z axis
	glm::vec3 scale; ///< Scale of the entity
	glm::mat4 model; ///< Model matrix 
	float relativeHeight; ///< Relative height within the world - models start at different sizes so scales are different

public:

	Transform();
	/**
	* \brief Sets the position of the entity
	*/
	void setPos(glm::vec3 pos);
	/**
	* \brief Adds to the position of the entity
	*/
	void addPos(glm::vec3 pos);
	/**
	* \brief Returns the position of the entity
	*/
	glm::vec3 getPos();
	/**
	* \brief Sets the rotation of the entity in each axis
	*/
	void setRot(float rotX, float rotY, float rotZ);
	/**
	* \brief Adds to the rotation of the entity in each axis
	*/
	void addRot(float rotX, float rotY, float rotZ);
	/**	
	* \brief Returns the rotation in the Y axis
	*/
	float getRotY();
	/**
	* \brief Returns the rotation in the X axis
	*/
	float getRotX();
	/**
	* \brief returns the rotation in the Z axis
	*/
	float getRotZ();
	/**
	* \brief Sets the relative height of the entity
	*/
	void setRHeight(float height);
	/**
	* \brief Returns the relative height of the entity
	*/
	float getRHeight();
	/**
	* \brief Sets the scale of the entity in each axis
	*/
	void setScale(glm::vec3 _scale);
	/**
	* \brief Returns the scale of the entity
	*/
	glm::vec3 getScale();
	/**
	* \brief Applies all the transformations to the model matrix and returns the result
	*/
	glm::mat4 getModel();
};

#endif