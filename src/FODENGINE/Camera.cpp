#include "Camera.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

void Camera::cameraInit(float _angle)
{
	angle = _angle;
	pos = glm::mat4(1.0f);
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
}

void Camera::cameraInit(float _angle, char* _cubemap)
{
	angle = _angle;
	pos = glm::mat4(1.0f);
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
	makeTexture(_cubemap);

}

glm::vec3 Camera::getPos()
{
	return camPos;
}

glm::mat4 Camera::getView()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	viewMat = transform->getModel();
	return glm::inverse(viewMat);
}

glm::mat4 Camera::getProjection()
{
	projectMat = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 1000.0f);
	return projectMat;
}

std::sr1::shared_ptr<rend::RenderTexture> Camera::getRenderTarget()
{
	return cubemap;
}

void Camera::makeTexture(const char * _filePath)
{
	
	std::sr1::shared_ptr<Engine> eng = getCore();
	std::sr1::shared_ptr<rend::RenderTexture> tex = eng->context->createRenderTexture();
	tex->setSize(512, 512);

	/*
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

		/*for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				tex->(x, y, glm::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}

		stbi_image_free(data);
		*/
	//}
	cubemap = tex;
}