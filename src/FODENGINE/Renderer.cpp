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



Renderer::~Renderer()
{
}

void Renderer::renderInit(char* _shader, char* _model, char* _texture, bool skybox, std::shared_ptr<Camera> cam)
{
	//stbi_set_flip_vertically_on_load(true);
	camera = cam;
	//ortho = skybox;
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

	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();


	shader->setUniform("u_View", camera->getView());
	/*glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/
	//if (!ortho)
	//{
		shader->setUniform("u_Projection", camera->getProjection());
	//}
	shader->setUniform("u_Model", transform->getModel());
	shader->setMesh(mesh);
	shader->render();
}

