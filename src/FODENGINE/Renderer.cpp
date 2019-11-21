#define STB_IMAGE_IMPLEMENTATION

#include "Renderer.h"
#include "stb_image.h"



//
//const GLfloat positions[] = {
//  0.0f, 0.5f, 0.0f,
//  -0.5f, -0.5f, 0.0f,
//  0.5f, -0.5f, 0.0f
//};
//
//const GLfloat colors[] = {
//  1.0f, 0.0f, 0.0f, 1.0f,
//  0.0f, 1.0f, 0.0f, 1.0f,
//  0.0f, 0.0f, 1.0f, 1.0f
//};
//const GLchar *vertexShaderSrc =
//"attribute vec3 in_Position;" \
//"attribute vec4 in_Color;" \
//"" \
//"varying vec4 ex_Color;" \
//"" \
//"void main()" \
//"{" \
//"  gl_Position = vec4(in_Position, 1.0);" \
//"  ex_Color = in_Color;" \
//"}" \
//"";
//
//const GLchar *fragmentShaderSrc =
//"varying vec4 ex_Color;" \
//"void main()" \
//"{" \
//"  gl_FragColor = ex_Color;" \
//"}" \
//"";


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::renderInit(char* _shader, char* _model, char* _texture, bool _ortho)
{
	ortho = _ortho;
	std::sr1::shared_ptr<Engine> eng = getCore();
	shader = eng->context->createShader();
	{
		std::ifstream f(_shader);

		if (!f.is_open())
		{
			throw rend::Exception("Failed to open model");
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

		mesh->parse(obj);
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
			throw rend::Exception("Failed to open image");
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

void Renderer::onDisplay()
{

	angle += 0.5f;

	glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (!ortho)
	{
		shader->setUniform("u_Projection", glm::perspective(glm::radians(65.0f), 1.0f, 0.1f, 100.0f));
	}
	shader->setUniform("u_Model",
		glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(5, -2, 45))
	);

	shader->setMesh(mesh);
	shader->render();
}

