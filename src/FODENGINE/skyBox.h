#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include "engine.h"

/**
* \brief Component that makes a skybox stay central
*/
class Skybox : public Component
{
	std::shared_ptr<Camera> cam; ///< Pointer to the currently active camera
public:
	/**
	* \brief Update loop, matches the skybox position to the camera
	*/
	virtual void onUpdate();

};

#endif