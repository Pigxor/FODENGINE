#include "Camera.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

void Camera::cameraInit(float _angle)
{
	angle = _angle;
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
	if (ent->checkComponent<BoxCollider>())
	{
		ent->getComponent<BoxCollider>()->setActive(active);
	}
	frametimer = 0;
}


glm::vec3 Camera::getPos()
{
	return camPos;
}

void Camera::onUpdate()
{

	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	camPos = transform->getPos();
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_EQUALS])
	{
		changeCamera(1);
	}
	if (state[SDL_SCANCODE_MINUS])
	{
		changeCamera(-1);
	}
	if (ent->checkComponent<BoxCollider>())
	{
		ent->getComponent<BoxCollider>()->setActive(active);
	}
	if (frametimer > 0)
	{
		frametimer--;
	}
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

void Camera::changeCamera(int num)
{
	if (active && frametimer == 0)
	{
		int newID = ID + num;
		std::shared_ptr<Engine> eng = getEngine();
		if (newID >= eng->getCamsSize())
		{
			setActive(false);
			eng->getCamera(0)->setActive(true);
			eng->getCamera(0)->setFtimer(20);
		}
		if (newID < 0)
		{
			setActive(false);
			eng->getCamera(eng->getCamsSize() - 1)->setActive(true);
			eng->getCamera(eng->getCamsSize() - 1)->setFtimer(20);
		}
		else if (newID < eng->getCamsSize() && newID > -1)
		{
			setActive(false);
			eng->getCamera(newID)->setActive(true);
			eng->getCamera(newID)->setFtimer(20);
		}
	}
}

void Camera::pickCamera(int num)
{
	std::shared_ptr<Engine> eng = getEngine();
	if (ID + num < eng->getCamsSize() && ID + num > -1)
	{
		setActive(false);
		eng->getCamera(ID + num)->setActive(true);
	}
	else
	{
		std::cout << "Trying to activate a non-existent camera" << std::endl;
	}
}

void Camera::setID(int id)
{
	ID = id;
}

void Camera::setFtimer(int timer)
{
	frametimer = timer;
}

