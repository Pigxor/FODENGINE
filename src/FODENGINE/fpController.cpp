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

void FPContoller::FPContollerInit(std::shared_ptr<Camera> Cam, glm::vec3 Offset)
{
	cam = Cam;
	offset = Offset;
	firstperson = false;
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
		if (firstperson)
		{
			pos += (right*movespeed);
		}
		else
		{
			pos -= (right*movespeed);
		}
	}
	if (state[SDL_SCANCODE_A])
	{
		if (firstperson)
		{
			pos -= (right*movespeed);
		}
		else
		{
			pos += (right*movespeed);
		}
	}
	if (state[SDL_SCANCODE_W])
	{
		if (firstperson)
		{
			pos += (fwd*movespeed);
		}
		else
		{
			pos -= (fwd*movespeed);
		}
	}
	if (state[SDL_SCANCODE_S])
	{
		if (firstperson)
		{
			pos -= (fwd*movespeed);
		}
		else
		{
			pos += (fwd*movespeed);
		}
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		if (ent->checkComponent<Physics>())
		{
			if (ent->getComponent<BoxCollider>()->getLanded())
			{
				ent->getComponent<Physics>()->addVelocity(glm::vec3(0, 1 * movespeed, 0));
				ent->getComponent<Physics>()->setGrav(-9.81);
				ent->getComponent<BoxCollider>()->setLanded(false);
			}
		}
		else
		{
			pos += (up*movespeed * 5.0f);
		}
	}
	if (state[SDL_SCANCODE_LSHIFT])
	{
		pos -= (up*movespeed * 5.0f);
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
	if (!firstperson)
	{
		active = cam->getActive();
	}
	if (active)
	{
		if (ent->checkComponent<Camera>())
		{
			if (ent->getComponent<Camera>()->getActive())
			{
				std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;

				transform->setPos(pos);
				transform->setRot(angleY, angleX, transform->getRotZ());
			}
		}
		else
		{
			if (!firstperson && cam->getActive())
			{
				std::shared_ptr<Transform> camTran = cam->getEntity()->getComponent<Transform>();
				camTran->setPos(pos);
				camTran->setRot(angleY, angleX+180, transform->getRotZ());
				camTran->setPos(pos - (offset.z*fwd) - (offset.y*up) - (offset.x * right));
				transform->setPos(pos);
				transform->setRot(transform->getRotX(), angleX, transform->getRotZ());
				std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
			}
			else
			{
				std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;

				transform->setPos(pos);
				transform->setRot(angleY, angleX, transform->getRotZ());
			}
		}
	}
}

void FPContoller::setMovespeed(float movs)
{
	movespeed = movs;
}
