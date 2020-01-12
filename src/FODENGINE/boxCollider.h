#ifndef _BOX_COLLIDER_H_
#define _BOX_COLLIDER_H_

#include "engine.h"

class BoxCollider : public Component
{
	glm::vec3 size;
	glm::vec3 offset;// = glm::vec3(1, 1, 1);
	glm::vec3 lastPos;

	void onUpdate();
	void staticMeshCollide();
	void boxCollide();
	bool isColliding(glm::vec3 pos, glm::vec3 Size);
	glm::vec3 getCollResponse(glm::vec3 pos, glm::vec3 size);

public:
	void boxCollInit();
	void setOffset(glm::vec3 Offset);
	void setSize(glm::vec3 Size);

	
};

#endif