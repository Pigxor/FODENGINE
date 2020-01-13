

#include "Renderer.h"



Renderer::~Renderer()
{
}

void Renderer::renderInit(char* _shader, char* _model, char* _texture, bool skybox)
{
	//stbi_set_flip_vertically_on_load(true);
	//ortho = skybox;
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

		mesh->parse(obj,skybox);
	}
	tex = eng->context->createTexture();
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char* data = stbi_load(_texture,
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


		mesh->setTexture("u_Texture", tex);

	}
}

std::sr1::shared_ptr<rend::Mesh> Renderer::getMesh()
{
	return mesh;
}

void Renderer::onDisplay()
{
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0);
	glEnable(GL_DEPTH_TEST);

	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camera = getEngine()->getActiveCam();

	shader->setUniform("u_View", camera->getView());
	shader->setUniform("u_Projection", camera->getProjection());
	shader->setUniform("u_Model", transform->getModel());
	shader->setMesh(mesh);

	shader->render();
}

