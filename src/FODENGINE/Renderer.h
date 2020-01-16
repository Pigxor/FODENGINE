#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;


/**
* \brief Component basic renderer for objects
* Includes a light position within the shader
*/
class Renderer : public Component
{

	std::sr1::shared_ptr<rend::Shader> shader; ///< Pointer to the shader being used
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< Pointer to the mesh being used
	std::sr1::shared_ptr<rend::Texture> tex; ///< Pointer to the texture being used
	std::sr1::shared_ptr<Camera> camera; ///< Pointer to the currently active camera
	bool sky = false; ///< Bool that controls if the object is a skybox or not

public:

	~Renderer();
	/**
	* \brief Initialised the renderer, loads model, texture and shader from files
	*/
	void renderInit(char* _shader, char* _model,char* _texture,bool skybox);
	/**
	* \brief Returns a pointer the the mesh that is being used
	*/
	std::sr1::shared_ptr<rend::Mesh> getMesh();
	/**
	* \brief Render everything to the screen
	*/
	void onDisplay();
};

#endif