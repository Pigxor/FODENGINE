#ifndef _2DANIMATION_H_
#define  _2DANIMATION_H_
#include "engine.h"

#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;


/**
* \brief Component that renders a 2d sprite animation
*/
class SpriteAnim : public Component
{
	glm::vec4 pos; ///< X and Y positions of the gui animation, also the x and y scale
	std::sr1::shared_ptr<rend::Shader> shader; ///< The shader used
	std::sr1::shared_ptr<rend::Texture> tex; ///< Texture pointer that is overwritten each time a texture is added
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< The 'mesh', the final positions of the gui
	std::sr1::shared_ptr<rend::Buffer> posBuffer; ///< Buffer containing the positions
	std::sr1::shared_ptr<rend::Buffer> texBuffer; ///< Buffer containing the texture coordinates
	std::sr1::shared_ptr<Camera> camera; ///< Pointer to the currently active camera
	std::vector<std::shared_ptr<rend::Texture>> frames; /// Vector of textures that are the frames of the animations
	bool reverse = false; ///< Bool that makes the animation reverse
	int currFrame; ///< The current frame of animation aka the current texture
	int frameTimer = 0; ///< Timer between frames so that it doesn't run through too quickly
public:

	~SpriteAnim();
	/**
	* \brief Initialises the renderer, takes in the shader the user wants to use
	*/
	void renderInit(char* _shader);
	/**
	* \brief Sets the X-Y position and the X-Y scale
	*/
	void setPosSize(glm::vec4 size);
	/**
	* \brief Adds a texture from a file into the vector of textures used for animation
	*/
	void addSprite(char* _texture);
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