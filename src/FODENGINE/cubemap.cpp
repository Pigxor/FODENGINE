#define STB_IMAGE_IMPLEMENTATION
#include "cubemap.h"
#include "stb_image.h"

void Cubemap::cubemapInit(char * _cubetex)
{
	stbi_set_flip_vertically_on_load(true);
	int w, h, compNo;
	float *data = stbi_loadf(_cubetex, &w, &h, &compNo, 0);
	unsigned int hdrTex;
	if (data)
	{
		glGenTextures(1, &hdrTex);
		glBindTexture(GL_TEXTURE_2D, hdrTex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, w, h, 0, GL_RGB, GL_FLOAT, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		stbi_image_free(data);
	}
	else
	{
		std::cout << "cubemapTex Fail";
	}


}

void Cubemap::onDisplay()
{
}
