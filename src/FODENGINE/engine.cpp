#include "engine.h"


Engine::~Engine()
{
	alcMakeContextCurrent(NULL);
	alcDestroyContext(acontext);
	alcCloseDevice(device);
	SDL_GL_DeleteContext(&context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

std::shared_ptr<Engine> Engine::initialize()
{
	std::shared_ptr<Engine> engine = std::make_shared<Engine>();
	engine->self = engine;
	engine->lastT = SDL_GetTicks();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw rend::Exception("SDL Failed To Initialise ");
	}

	engine->window = SDL_CreateWindow("FODEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(engine->window))
	{
		throw rend::Exception("Window Failed To Initialise ");
	}
	//AL device
	engine->device = alcOpenDevice(NULL);
	
	if (engine->device == NULL)
	{
		throw rend::Exception("Audio Device Is Null");
	}
	engine->acontext = alcCreateContext(engine->device, NULL);
	if (engine->acontext == NULL)
	{
		alcCloseDevice(engine->device);
		throw rend::Exception("Audio Context Failed");
	}
	if (!alcMakeContextCurrent(engine->acontext))
	{
		alcDestroyContext(engine->acontext);
		alcCloseDevice(engine->device);
		throw rend::Exception("Current Audio Context Failed");
	}
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	engine->context = rend::Context::initialize();

	return engine;
}

std::shared_ptr<Entity> Engine::addEntity(const char* nme)
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	std::shared_ptr<Transform> entTransf = entity->addComponent<Transform>();
	entities.push_back(entity);
	entity->engine = self;
	entity->self = entity;
	entity->name = nme;
	return entity;
}

std::shared_ptr<Camera> Engine::getCamera(int i)
{
	return Cams[i];
}

SDL_Window * Engine::getWindow()
{
	return window;
}

std::shared_ptr<Camera> Engine::getActiveCam()
{
	for (std::vector<std::shared_ptr<Camera>>::iterator it = Cams.begin(); it != Cams.end(); it++)
	{
		if ((*it)->getActive())
		{
			return (*it);
		}
	}
}

std::shared_ptr<Camera> Engine::addCamera(int angle)
{
	const char* name = "Camera";
	std::shared_ptr<Entity> camEnt = addEntity(name);
	std::shared_ptr<Transform> camTransform = camEnt->addComponent<Transform>();
	std::shared_ptr<Camera> cam = camEnt->addComponent<Camera>();
	cam->cameraInit(angle);
	camEnt->engine = self;
	camEnt->self = camEnt;
	cam->setID(Cams.size());
	cam->setActive(false);
	Cams.push_back(cam);
	return cam;
}

std::shared_ptr<Entity> Engine::addBox(glm::vec3 pos, glm::vec3 scale, glm::vec3 rots, const char* nme)
{
	std::shared_ptr<Entity> box = addEntity(nme);
	std::shared_ptr<Renderer> boxR = box->addComponent<Renderer>();
	std::shared_ptr<BoxCollider> boxBC = box->addComponent<BoxCollider>();
	boxR->renderInit("../shaders/basicShader.txt", "../models/cube.obj", "../models/grey.png", false);
	box->getComponent<Transform>()->setPos(pos);
	box->getComponent<Transform>()->setScale(scale);
	box->getComponent<Transform>()->setRot(rots.x, rots.y, rots.z);
	boxBC->boxCollInit(true);
	boxBC->setSize(scale);
	boxBC->setOffset(glm::vec3(0, 0, 0));
	boxBC->setMoveable(false);
	return box;
}

int Engine::getCamsSize()
{
	return Cams.size();
}

std::sr1::shared_ptr<rend::Context> Engine::getContext()
{
	return context;
}

void Engine::start()
{

	bool quit = false;

	while (!quit)
	{
		glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		T = SDL_GetTicks();
		diff = T - lastT;
		deltaT = diff / 1000;
		float idealTime = 1.0f / 60.0f;
		if (idealTime > deltaT)
		{
			SDL_Delay((idealTime - deltaT)*1000.0f);
		}
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (state[SDL_SCANCODE_ESCAPE] || (event.type == SDL_QUIT))
			{
				quit = true;
			}
		}	

		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Update();
		}
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Display();
		}
		SDL_GL_SwapWindow(window);
		lastT = T;
	}
	
}

void Engine::stop()
{
}

float Engine::getDeltaT()
{
	return deltaT;
}


