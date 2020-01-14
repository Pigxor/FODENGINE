#include "fpController.h"

FPContoller::FPContoller()
{
	glm::mat4 t(1.0f);
	t = glm::mat4(1.0f);
	t = glm::rotate(t, glm::radians(angleX), glm::vec3(0, 1, 0));
	t = glm::translate(t, glm::vec3(0, 1, 0));
	up = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	up = glm::normalize(up);

}

void FPContoller::onUpdate()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	std::sr1::shared_ptr<Engine> eng = getEngine();
	angleY = transform->getRotX();
	angleX = transform->getRotY();
	pos = transform->getPos();
	//F-B Movement
	glm::mat4 t(1.0f);
	t = glm::rotate(t, glm::radians(angleX), glm::vec3(0, 1, 0));
	t = glm::translate(t, glm::vec3(0, 0, -1));
	fwd = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	fwd = glm::normalize(fwd);
	//L-R Movement
	t = glm::mat4(1.0f);
	t = glm::rotate(t, glm::radians(angleX), glm::vec3(0, 1, 0));
	t = glm::translate(t, glm::vec3(1, 0, 0));
	right = t * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	right = glm::normalize(right);
	
	if (cursorLock)
	{
		const Uint32 mouse = SDL_GetMouseState(&mouseX, &mouseY);
		if (mouseX > (WINDOW_WIDTH / 2))
		{
			angleX -= rotspeed;
		}
		if (mouseX < (WINDOW_WIDTH / 2))
		{
			angleX += rotspeed;
		}
		if (mouseY > (WINDOW_HEIGHT / 2))
		{
			angleY -= rotspeed;
		}
		if (mouseY < (WINDOW_HEIGHT / 2))
		{
			angleY += rotspeed;
		}
	}

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_D])
	{
		pos += (right*movespeed);
	}
	if (state[SDL_SCANCODE_A])
	{
		pos -= (right*movespeed);
	}
	if (state[SDL_SCANCODE_W])
	{
		pos += (fwd*movespeed);
	}
	if (state[SDL_SCANCODE_S])
	{
		pos -= (fwd*movespeed);
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		pos += (up*movespeed);
	}
	if (state[SDL_SCANCODE_LSHIFT])
	{
		pos -= (up*movespeed);
	}
	if (state[SDL_SCANCODE_L])
	{
		if (cursorLock == true)
		{
			cursorLock = false;
		}
	}
	if (state[SDL_SCANCODE_K])
	{
		if (cursorLock == false)
		{
			cursorLock = true;
		}
	}
	if (cursorLock == false)
	{
		SDL_ShowCursor(1);
		SDL_SetWindowGrab(eng->getWindow(), SDL_FALSE);
	}
	if (cursorLock == true)
	{
		SDL_ShowCursor(0);
	    SDL_SetWindowGrab(eng->getWindow(), SDL_TRUE);
		SDL_WarpMouseInWindow(eng->getWindow(), (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2));
	}
	if (ent->getComponent<Camera>()->getActive())
	{
		std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;

		transform->setPos(pos);
		transform->setRot(angleY, angleX, transform->getRotZ());
	}
}

void FPContoller::setMovespeed(float movs)
{
	movespeed = movs;
}
