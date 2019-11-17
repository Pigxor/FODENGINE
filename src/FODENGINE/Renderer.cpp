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

const char* src =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"attribute vec3 a_Normal;                      \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"uniform mat4 u_Model;                         \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_Position = u_Projection *                \n" \
"    u_Model * vec4(a_Position, 1);            \n" \
"                                              \n" \
"  v_Normal = a_Normal;                        \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"uniform sampler2D u_Texture;                  \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";


Renderer::Renderer()
{

	//
	//if (glewInit() != GLEW_OK)
	//{
	//	throw rend::Exception("Glew Failed To Initialise ");
	//}

	//GLuint positionsVboId = 0;

	//// Create a new VBO on the GPU and bind it
	//glGenBuffers(1, &positionsVboId);

	//if (!positionsVboId)
	//{
	//	throw rend::Exception("PositionsVBO Failed ");
	//}

	//glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);

	//// Upload a copy of the data from memory into the new VBO
	//glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	//// Reset the state
	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	//GLuint colorsVboId = 0;

	//// Create a colors VBO on the GPU and bind it
	//glGenBuffers(1, &colorsVboId);

	//if (!colorsVboId)
	//{
	//	throw rend::Exception("ColoursVBO Failed ");
	//}

	//glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);

	//// Upload a copy of the data from memory into the new VBO
	//glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	//// Reset the state
	//glBindBuffer(GL_ARRAY_BUFFER, 0);

	//vaoId = 0;

	//// Create a new VAO on the GPU and bind it
	//glGenVertexArrays(1, &vaoId);

	//if (!vaoId)
	//{
	//	throw rend::Exception("Vao Failed ");
	//}

	//glBindVertexArray(vaoId);

	//// Bind the position VBO, assign it to position 0 on the bound VAO and flag it to be used
	//glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0);
	//glEnableVertexAttribArray(0);

	//// Bind the color VBO, assign it to position 1 on the bound VAO and flag it to be used
	//glBindBuffer(GL_ARRAY_BUFFER, colorsVboId);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
	//glEnableVertexAttribArray(1);

	//// Reset the state
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);

	//GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
	//glCompileShader(vertexShaderId);
	//GLint success = 0;
	//glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	//if (!success)
	//{
	//	throw rend::Exception("Failed To Get Vertex Shader ");
	//}

	//GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
	//glCompileShader(fragmentShaderId);
	//glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	//if (!success)
	//{
	//	throw rend::Exception("Failed To Get Fragment Shader ");
	//}

	//programId = glCreateProgram();
	//glAttachShader(programId, vertexShaderId);
	//glAttachShader(programId, fragmentShaderId);
	//glBindAttribLocation(programId, 0, "in_Position");
	//glBindAttribLocation(programId, 1, "in_Color");

	//if (glGetError() != GL_NO_ERROR)
	//{
	//	throw rend::Exception("Failed To Bind Attibute ");
	//}

	//glLinkProgram(programId);
	//glGetProgramiv(programId, GL_LINK_STATUS, &success);

	//if (!success)
	//{
	//	throw rend::Exception("Failed To Link Program ");
	//}

	//glDetachShader(programId, vertexShaderId);
	//glDeleteShader(vertexShaderId);
	//glDetachShader(programId, fragmentShaderId);
	//glDeleteShader(fragmentShaderId);
}

Renderer::~Renderer()
{
}

void Renderer::renderInit()
{
	std::sr1::shared_ptr<Engine> eng = getCore();
	shader = eng->context->createShader();
	shader->parse(src);

	mesh = eng->context->createMesh();
	{
		std::ifstream f("../models/graveyard.obj");

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

		unsigned char* data = stbi_load("../models/graveyard.png",
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

	angle += 0.005f;

	glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shader->setUniform("u_Projection", glm::perspective(glm::radians(65.0f), 1.0f, 0.1f, 100.0f));

	shader->setUniform("u_Model",
		glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1, 0, 0)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0)) *
		glm::translate(glm::mat4(1.0f), glm::vec3(5, -2, 45))
	);

	shader->setMesh(mesh);
	shader->render();
}

