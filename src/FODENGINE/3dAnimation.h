#ifndef _3DANIMATION_H_
#define  _3DANIMATION_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;

/**
* \brief Component that renders a 3d model animation
*/
class ModelAnim : public Component
{
	std::sr1::shared_ptr<rend::Shader> shader; ///< The shader used
	std::sr1::shared_ptr<rend::Texture> tex; ///< Texture pointer that is overwritten each time a texture is added 
	std::vector<std::sr1::shared_ptr<rend::Mesh>> meshes; ///< Vecctor of meshes used for the animations
	std::shared_ptr<rend::Mesh> mesh; ///< The 'mesh', the final positions of the model vertices
	std::sr1::shared_ptr<Camera> camera; ///< Pointer to the currently active camera
	std::vector<std::shared_ptr<rend::Texture>> frames; ///< Vector of textures used to stor ethe texture, incase of animated textures
	bool reverse = false;  ///< Bool that makes the animation reverse
	int currFrame; ///< The current frame of animation aka the current model
	int frameTimer = 0; ///< Timer between frames so that it doesn't run through too quickly
public:

	~ModelAnim();
	/**
	* \brief Initialises the renderer, takes in the shader the user wants to use
	*/
	void renderInit(char* _shader);
	/**
	* \brief Adds a texture from a file into the vector of textures used for animated textures
	*/
	void addTex(char* _texture);
	/**
	* \brief Adds a mesh to the vector, used for animations
	*/
	void addMesh(char* _texture);
	/**
	* \brief Displays to the screen
	*/
	void onDisplay();
	/**
	* \brief Contains a loop that moves through the frames vector
	*/
	void onUpdate();
};

#endif