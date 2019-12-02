#ifndef _PBR_H_
#define _PBR_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;



class PBR : public Component
{

	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Texture> tex;
	std::sr1::shared_ptr<rend::Texture> norm;
	std::sr1::shared_ptr<rend::Texture> alb;
	std::sr1::shared_ptr<rend::Texture> met;
	std::sr1::shared_ptr<rend::Texture> ruf;
	std::sr1::shared_ptr<rend::Texture> ao;

	std::sr1::shared_ptr<Camera> camera;

	//glm::vec3 albedo;
	//float metallic;
	//float roughness;
	//float ao;
	glm::vec3 lightPos[4];
	glm::vec3 lightColour[4];
	glm::vec3 camPos;

	float angle = 0;
	bool ortho = false;

public:

	PBR();
	void renderInit(char* _shader, char* _model, char* _texture, bool _ortho, std::shared_ptr<Camera> cam, char* _metallic, char* _roughness, char* _ao, char* _albedo, char* _normal);
	virtual  void onDisplay();
	std::sr1::shared_ptr<rend::Texture> makeTexture(const char* _filePath);
};

#endif#pragma once
