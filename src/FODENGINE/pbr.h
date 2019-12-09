#ifndef _PBR_H_
#define _PBR_H_
#include "engine.h"


#include <rend/rend.h>
#include <sr1/memory>
#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>

class Camera;
class Renderer;
class Transform;

class PBR : public Component
{

	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Shader> cubeShader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr<rend::Mesh> cubeMesh;
	std::sr1::shared_ptr<rend::Texture> tex;
	std::sr1::shared_ptr<rend::Texture> norm;
	std::sr1::shared_ptr<rend::Texture> alb;
	std::sr1::shared_ptr<rend::Texture> met;
	std::sr1::shared_ptr<rend::Texture> ruf;
	std::sr1::shared_ptr<rend::Texture> ao;
	std::sr1::shared_ptr<rend::Texture> IMap;

	std::sr1::shared_ptr<Transform> skybox;

	std::sr1::shared_ptr<rend::Texture> cubeTex;

	std::sr1::shared_ptr<Camera> camera;
	std::sr1::shared_ptr<Camera> cameraRenderTex;

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
	void renderInit(char* _shader, char* _model, char* _texture, std::shared_ptr<Transform> _skybox, std::shared_ptr<Camera> cam, std::shared_ptr<Camera> camRT, char* _metallic, char* _roughness, char* _ao, char* _albedo, char* _normal, char* _imap);
	virtual  void onDisplay();
	std::sr1::shared_ptr<rend::Texture> makeTexture(const char* _filePath);
	void cubemapInit(char* _hdrFile, char* _cubeShader, char* _skybox);

};

#endif#pragma once
