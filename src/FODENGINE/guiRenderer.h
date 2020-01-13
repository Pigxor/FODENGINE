#ifndef _GUIRENDERER_H_
#define _GUIRENDERER_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;



class GUIRenderer : public Component
{

	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;
	glm::vec4 pos;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Texture> tex;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Buffer> posBuffer;
	std::sr1::shared_ptr<rend::Buffer> texBuffer;
	std::sr1::shared_ptr<Camera> camera;

	float angle = 0;
	bool ortho = false;

public:

	~GUIRenderer();
	void renderInit(char* _shader, char* _texture);
	void setPosSize(glm::vec4 size);
	void onDisplay();
};

#endif