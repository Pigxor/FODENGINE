#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "component.h"
#include <rend/rend.h>



class Triangle : public Component
{

	SDL_Window *window;
	GLuint programId;
	GLuint vaoId;

public:
	Triangle();
	~Triangle();

	virtual  void onDisplay();
};

#endif