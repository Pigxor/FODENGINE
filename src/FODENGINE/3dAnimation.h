#ifndef _3DANIMATION_H_
#define  _3DANIMATION_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;



class ModelAnim : public Component
{
	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;
	glm::vec4 pos;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Texture> tex;
	std::vector<std::sr1::shared_ptr<rend::Mesh>> meshes;
	std::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<Camera> camera;
	std::vector<std::shared_ptr<rend::Texture>> frames;
	float angle = 0;
	bool reverse = false;
	int currFrame;
	int frameTimer = 0;
public:

	~ModelAnim();
	void renderInit(char* _shader);
	void addTex(char* _texture);
	void addMesh(char* _texture);
	void onDisplay();
	void onUpdate();
};

#endif