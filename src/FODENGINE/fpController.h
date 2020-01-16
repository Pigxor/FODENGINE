#ifndef _FPCONTROLLER_H_
#define _FPCONTROLLER_H_

#include "engine.h"

/**
* \brief Component that allows the use to control an object
*/
class FPController : public Component
{
	glm::vec3 fwd; ///< Relative forward vector
	glm::vec3 right; ///< Relative right vector
	glm::vec3 up; ///< Upwards vector

	glm::vec3 pos; ///< Posiion to be passed into the transform

	float movespeed = 0.5f; ///< Movement speed
	float rotspeed = 1.5f; ///< Rotation Speed
	float angleX; ///< Rotation angle in the x axis
	float angleY; ///< Rotation angle in the y axis
	int inputNum; ///< Input value passed from the engine
	int mouseX; ///< X coordinate of the mouse cursor
	int mouseY; ///< Y cooordinate fo the cursor
	std::shared_ptr<Camera> cam; ///< Pointer to an attached camera
	glm::vec3 offset; ///< Camera offset from object
	bool cursorLock = true; ///< Bool controls if the cursor is invisible and locked to the center of the screen
	bool firstperson = true; ///< Bool controls if the FPController is in first of third person
public:

	FPController();
	/**
	* \brief Initialises the FPController for a thir person camera
	*/
	void FPContollerInit(std::shared_ptr<Camera> Cam, glm::vec3 Offset);
	/**
	* \brief Update loop that checks for inputs and controls the positions and rotatios fo an object and camera
	* Also checks for inputs that control the cursor lock
	*/
	void onUpdate();
	/**
	* \brief Sets the movement speed to a specific value
	*/
	void setMovespeed(float movs);

};


#endif