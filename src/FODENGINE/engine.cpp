#include "engine.h"


#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 760

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

std::shared_ptr<Entity> Engine::addEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entities.push_back(entity);
	entity->engine = self;
	entity->self = entity;
	return entity;
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
		deltaT = diff / 2000;
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
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


