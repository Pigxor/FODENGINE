#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;



class Renderer : public Component
{

	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Texture> tex;
	std::sr1::shared_ptr<Camera> camera;
	float angle = 0;
	bool sky = false;

public:

	~Renderer();
	void renderInit(char* _shader, char* _model,char* _texture,bool skybox);
	std::sr1::shared_ptr<rend::Mesh> getMesh();
	void onDisplay();
};

#endif