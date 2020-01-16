#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "engine.h"

/**
* \brief Component provides a camera with view/projection matrix etc
*/
class Camera : public Component
{
	int ID; ///< Identity number of the camera
	int frametimer; ///< Timer to stop camera switching happening too fast
	glm::mat4 viewMat; ///<  View Matrix, used for rendering things to the screen
	glm::mat4 projectMat; ///< Projection matrix, used for rendering things to the screen
	float angle; ///< View angle / Zoom
	glm::vec3 camPos; ///< Position Vector
public :
	/**
	* \brief Initial set-up of the component, sets the view angle
	*/
	void cameraInit(float _angle);
	/**
	* \brief Returns the camera position
	*/
	glm::vec3 getPos();
	/**	
	* \brief Update loop, handles inputs for switching the current camera
	*/
	void onUpdate();
	/**
	* \brief Calculates and returns the view matrix
	*/
	glm::mat4 getView();
	/**
	* \brief Returns the projections matrix
	*/
	glm::mat4 getProjection();
	/**
	* \brief Allows user to change the next or previous camera in the vector of cameras
	* The vector fo cameeras is stored in the engine
	*/
	void changeCamera(int num);
	/**
	* \brief Allows the user to change to a specific camera	
	*/
	void pickCamera(int num);
	/**
	* \brief Sets the camera identity number
	*/
	void setID(int id);
	/**
	* \brief Sets the frame timer to control camera switch speed
	*/
	void setFtimer(int timer);
};


#endif