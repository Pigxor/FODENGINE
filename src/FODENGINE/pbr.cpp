
#include "pbr.h"
#include "stb_image.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

PBR::PBR()
{
	lightPos[0] = glm::vec3(-15, 0, 2);
	lightPos[1] = glm::vec3(10, 0, 5);
	lightPos[2] = glm::vec3(10, 0, 5);
	lightPos[3] = glm::vec3(10, 0, 5);
	
	lightColour[0] = glm::vec3(300, 300, 300); //strength
	lightColour[1] = glm::vec3(0,0, 0);
	lightColour[2] = glm::vec3(0,0, 0);
	lightColour[3] = glm::vec3(0, 0, 0);
}

void PBR::renderInit(char* _shader, char* _model, char* _texture, std::shared_ptr<Renderer> _skybox, std::shared_ptr<Camera> cam, std::shared_ptr<Camera> camRT, char* _metallic, char* _roughness, char* _ao, char* _albedo, char* _normal, char* _imap)
{
	//metallic = _metallic;
	//roughness = _roughness;
	//ao = _ao;
	//albedo = _albedo;
	skybox = _skybox;
	camera = cam;
	cameraRenderTex = camRT;

	//ortho = _ortho;
	std::sr1::shared_ptr<Engine> eng = getCore();
	shader = eng->context->createShader();
	{
		std::ifstream f(_shader);

		if (!f.is_open())
		{
			throw rend::Exception("Failed to open shader");
		}

		std::string shade;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			shade += line + "\n";
		}

		shader->parse(shade);
	}
	mesh = eng->context->createMesh();
	{
		std::ifstream f(_model);

		if (!f.is_open())
		{
			throw rend::Exception("Failed to open model");
		}

		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}

		mesh->parse(obj,false);
	}
	tex = makeTexture(_texture);
	norm = makeTexture(_normal);
	met = makeTexture(_metallic);
	ruf = makeTexture(_roughness);
	alb = makeTexture(_albedo);
	ao = makeTexture(_ao);
	IMap = makeTexture(_imap);

	mesh->setTexture("IMap", IMap);
	mesh->setTexture("u_Texture", tex);
	mesh->setTexture("normalM", norm);
	mesh->setTexture("metallicM", met);
	mesh->setTexture("roughnessM", ruf);
	mesh->setTexture("albedoM", alb);
	mesh->setTexture("aoM", ao);

}

void PBR::onDisplay()
{
	std::sr1::shared_ptr<Engine> eng = getCore();
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	
	//transform->addRot(0, 1, 0);u_M

	//shader->setUniform("sky_Model", skybox->getEntity()->getComponent<Transform>()->getModel());
	shader->setUniform("u_Projection", camera->getProjection());
	shader->setUniform("u_View", camera->getView());
	shader->setUniform("camPos", camera->getPos());
	//shader->setUniform("albedo", albedo);
	//shader->setUniform("metallic", metallic);
	//shader->setUniform("roughness", roughness);
	//shader->setUniform("ao", ao);
	//for (unsigned int i = 0; i < sizeof(lightPos) / sizeof(lightPos[0]); ++i)
	//{
	//	glm::vec3 newPos = lightPos[i] + glm::vec3(sin(eng->deltaT*0.3f) * 5.0, 0.0, 0.0);
	//	lightPos[i] = newPos;	
	//	shader->setUniform("lightColour[" + std::to_string(i) + "]", lightColour[i]);
	//	shader->setUniform("lightPos[" + std::to_string(i) + "]",lightPos[i]);
	//
	//}
	shader->setUniform("u_Model", transform->getModel(camera));
	//shader->setMesh(skybox->getMesh());
	shader->setMesh(mesh);

	if (cameraRenderTex->getRenderTarget() != NULL)
	{
		shader->render(cameraRenderTex->getRenderTarget());
	}
	else
	{
		shader->render();
	}
	
	//THIS NEEDS WORK --  run through ach skybox camera
	if (camera->getRenderTarget() != NULL)
	{
		shader->render(camera->getRenderTarget());
	}
	else
	{
		shader->render();
	}

}

std::sr1::shared_ptr<rend::Texture> PBR::makeTexture(const char * _filePath)
{
	//stbi_set_flip_vertically_on_load(true);
	std::sr1::shared_ptr<Engine> eng = getCore();
	std::sr1::shared_ptr<rend::Texture> tex = eng->context->createTexture();
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char* data = stbi_load(_filePath,
			&w, &h, &bpp, 3);

		if (!data)
		{
			throw rend::Exception("Failed to open texture");
		}

		tex->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				tex->setPixel(x, y, glm::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}

		stbi_image_free(data);
	}
	return tex;
}




