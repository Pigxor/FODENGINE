#include "3dAnimation.h"



ModelAnim::~ModelAnim()
{
}

void ModelAnim::renderInit(char* _shader)
{

	std::sr1::shared_ptr<Engine> eng = getEngine();
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

}

void ModelAnim::addTex(char * _texture)
{

	std::sr1::shared_ptr<Engine> eng = getEngine();
	tex = eng->context->createTexture();
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char* data = stbi_load(_texture,
			&w, &h, &bpp, 4);

		if (!data)
		{
			throw rend::Exception("Failed to open texture");
		}

		tex->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 4 + x * 4;

				tex->setPixel(x, y, glm::vec4(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f, data[r + 3] / 255.0f));
			}
		}
		stbi_image_free(data);

	}
	frames.push_back(tex);

}

void ModelAnim::addMesh(char * _model)
{
	std::sr1::shared_ptr<Engine> eng = getEngine();
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

		mesh->parse(obj, false);
	}
	meshes.push_back(mesh);
}

void ModelAnim::onDisplay()
{
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0);
	glEnable(GL_DEPTH_TEST);

	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camera = getEngine()->getActiveCam();


	shader->setUniform("u_LightPos", glm::vec3(0, 3, 2));
	shader->setUniform("u_Emissive", glm::vec3(0.3, 0.3, 0.3));
	shader->setUniform("u_Ambient", glm::vec3(0.0, 0.0, 0.0));
	shader->setUniform("u_View", camera->getView());
	shader->setUniform("u_Projection", camera->getProjection());
	shader->setUniform("u_Model", transform->getModel());
	

	shader->render();
}

void ModelAnim::onUpdate()
{
	std::sr1::shared_ptr<Engine> eng = getEngine();
	if (frameTimer > 0)
	{
		frameTimer--;
	}


	if (frameTimer == 0)
	{

		if (reverse)
		{
			currFrame--;
		}
		else
		{
			currFrame++;
		}
		if (currFrame >= meshes.size())
		{
			reverse = true;
			currFrame--;
		}
		if (currFrame <= 0)
		{
			reverse = false;
		}


		frameTimer = 8;
	}
	mesh = meshes[currFrame];
	shader->setMesh(mesh);
	mesh->setTexture("u_Texture", frames[0]);
}

