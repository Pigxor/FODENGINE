#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>





class Renderer : public Component
{

	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Texture> tex;
	float angle = 0;

public:
	Renderer();
	~Renderer();
	void renderInit();
	virtual  void onDisplay();
};

#endif