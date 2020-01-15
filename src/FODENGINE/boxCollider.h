#ifndef _BOX_COLLIDER_H_
#define _BOX_COLLIDER_H_

#include "engine.h"

class BoxCollider : public Component
{
	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 lastPos;

	bool moveable;
	bool landed = false;
	bool floored = false;
	bool colls;
	void onUpdate();
	void staticMeshCollide();
	void boxCollide();
	bool isColliding(glm::vec3 pos, glm::vec3 Size);
	glm::vec3 getCollResponse(glm::vec3 pos, glm::vec3 size);

	std::vector<float> heights;
	std::vector<std::shared_ptr<Entity>> colliding;
public:
	void boxCollInit(bool Active);
	void setOffset(glm::vec3 Offset);
	void setSize(glm::vec3 Size);
	glm::vec3 getSize();
	bool checkColliding(glm::vec3 pos, glm::vec3 Size);
	bool getLanded();
	void setLanded(bool land);
	bool getFloored();
	void setFloored(bool Floored);
	void setMoveable(bool Active);
	bool getMoveable();
};

#endif