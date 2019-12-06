#ifndef _CUBEMAP_H_
#define _CUBEMAP_H_

#include"engine.h"

class Cubemap : public Component
{
	std::sr1::vector<char*> texture_faces;

public:
	void cubemapInit(char* _cubetex);
	virtual  void onDisplay();

};


#endif // !_CUBEMAP_H
