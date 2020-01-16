#include "2dAnimation.h"



SpriteAnim::~SpriteAnim()
{
}

void SpriteAnim::renderInit(char* _shader)
{
	currFrame = 0;
	std::sr1::shared_ptr<Engine> eng = getEngine();
	mesh = eng->context->createMesh();
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
	posBuffer = eng->context->createBuffer();
	{
		posBuffer->add(glm::vec2(0, 0));
		posBuffer->add(glm::vec2(0, 1));
		posBuffer->add(glm::vec2(1, 1));
		posBuffer->add(glm::vec2(1, 1));
		posBuffer->add(glm::vec2(1, 0));
		posBuffer->add(glm::vec2(0, 0));
		mesh->setBuffer("a_Position", posBuffer);
	}

	texBuffer = eng->context->createBuffer();
	{
		texBuffer->add(glm::vec2(0, 1));
		texBuffer->add(glm::vec2(0, 0));
		texBuffer->add(glm::vec2(1, 0));
		texBuffer->add(glm::vec2(1, 0));
		texBuffer->add(glm::vec2(1, 1));
		texBuffer->add(glm::vec2(0, 1));
		mesh->setBuffer("a_TexCoord", texBuffer);
	}

}

void SpriteAnim::setPosSize(glm::vec4 size)
{
	pos = size;
}

void SpriteAnim::addSprite(char * _texture)
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


void SpriteAnim::onDisplay()
{
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0);
	glDisable(GL_DEPTH_TEST);

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(pos.x, pos.y, 0));
	model = glm::scale(model, glm::vec3(pos.z, pos.w, 1));
	shader->setUniform("u_Projection", glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f, -1.0f, 1.0f));
	shader->setUniform("u_Model", model);
	shader->setMesh(mesh);
	shader->render();
}

void SpriteAnim::onUpdate()
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
		if (currFrame >= frames.size())
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
	mesh->setTexture("u_Texture", frames[currFrame]);
}

