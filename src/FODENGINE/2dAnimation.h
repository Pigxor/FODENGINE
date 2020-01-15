#ifndef _2DANIMATION_H_
#define  _2DANIMATION_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;



class SpriteAnim : public Component
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
	std::vector<std::shared_ptr<rend::Texture>> frames;
	float angle = 0;
	bool reverse = false;
	int currFrame;
	int frameTimer = 0;
public:

	~SpriteAnim();
	void renderInit(char* _shader);
	void setPosSize(glm::vec4 size);
	void addSprite(char* _texture);
	void onDisplay();
	void onUpdate();
};

#endif