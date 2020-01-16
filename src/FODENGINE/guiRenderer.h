#ifndef _GUIRENDERER_H_
#define _GUIRENDERER_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;

/**
* \brief Component for rendering a Gui image
*/
class GUIRenderer : public Component
{
	glm::vec4 pos; ///< Position of the image on the screen and the scale of the image
	std::sr1::shared_ptr<rend::Shader> shader; ///< Pointer to the shader used to render
	std::sr1::shared_ptr<rend::Texture> tex; ///< Pointer to the texture that needs to be rendered
	std::sr1::shared_ptr<rend::Mesh> mesh; ///< Final Positions that get passed into the renderer
	std::sr1::shared_ptr<rend::Buffer> posBuffer; ///< Buffer for the positions of gui (In this case the positons to render a square image
	std::sr1::shared_ptr<rend::Buffer> texBuffer; ///< Buffer for the texture coordinates
	std::sr1::shared_ptr<Camera> camera; ///< Pointer to the current active camera

public:

	~GUIRenderer();
	/**
	* \brief Initialise the gui with the texture and the shader wanted to render the image
	*/
	void renderInit(char* _shader, char* _texture);
	/**
	* \brief Sets the position and scale of the gui image
	*/
	void setPosSize(glm::vec4 size);
	/**
	* \brief Display the gui to the screen
	*/
	void onDisplay();
};

#endif