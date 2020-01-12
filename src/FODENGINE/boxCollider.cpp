#include "boxCollider.h"

void BoxCollider::onUpdate()
{
//	staticMeshCollide();
	boxCollide();
}

void BoxCollider::staticMeshCollide()
{
}

void BoxCollider::boxCollide()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	glm::vec3 newPos = transform->getPos() + offset;
	std::vector<std::sr1::shared_ptr<Entity>> objs;
	objs = getCore()->getEntities<BoxCollider>();
	for (std::vector<std::shared_ptr<Entity>>::iterator it = objs.begin(); it != objs.end(); it++)
	{
		if ((*it)->name != name)
		{
			glm::vec3 collResp = (*it)->getComponent<BoxCollider>()->getCollResponse(newPos, size);
			newPos = collResp;
			newPos = newPos - offset;
			transform->setPos(newPos);
			lastPos = newPos;
		}
	}
}

bool BoxCollider::isColliding(glm::vec3 pos, glm::vec3 Size)
{
	bool coll = false;
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	glm::vec3 apos = transform->getPos() + offset;
	glm::vec3 asize = size;

	glm::vec3 bpos = pos;
	glm::vec3 bsize = Size;


	if (apos.x > bpos.x)
	{
		if (apos.x - asize.x > bpos.x + bsize.x)
		{
			return false;
		}
	}
	else
	{
		if (bpos.x - bsize.x > apos.x + asize.x)
		{
			return false;
		}
	}

	if (apos.z > bpos.z)
	{
		if (apos.z - asize.z > bpos.z + bsize.z)
		{
			return false;
		}
	}
	else
	{
		if (bpos.z - bsize.z > apos.z + asize.z)
		{
			return false;
		}
	}

	if (apos.y > bpos.y)
	{
		if (apos.y - asize.y > bpos.y + bsize.y)
		{
			return false;
		}
	}
	else
	{
		if (bpos.y - bsize.y > apos.y + asize.y)
		{
			return false;
		}
	}

	return true;
}

glm::vec3 BoxCollider::getCollResponse(glm::vec3 pos, glm::vec3 size)
{
	float amount = 0.1f;
	float step = 0.1f;

	while (true)
	{
		if (!isColliding(pos, size)) break;
		pos.x += amount;
		if (!isColliding(pos, size)) break;
		pos.x -= amount;
		pos.x -= amount;
		if (!isColliding(pos, size)) break;
		pos.x += amount;
		pos.z += amount;
		if (!isColliding(pos, size)) break;
		pos.z -= amount;
		pos.z -= amount;
		if (!isColliding(pos, size)) break;
		pos.z += amount;
		pos.y += amount;
		if (!isColliding(pos, size)) break;
		pos.y -= amount;
		pos.y -= amount;
		if (!isColliding(pos, size)) break;
		pos.y += amount;
		amount += step;
	}

	return pos;
}



void BoxCollider::boxCollInit()
{
	std::sr1::shared_ptr<Entity> ent = getEntity();
	std::sr1::shared_ptr<Transform> transform = ent->getComponent<Transform>();
	size = glm::vec3(1, 1, 1);
	lastPos = transform->getPos();
}

void BoxCollider::setOffset(glm::vec3 Offset)
{
	offset = Offset;
}

void BoxCollider::setSize(glm::vec3 Size)
{
	size = Size;
}
