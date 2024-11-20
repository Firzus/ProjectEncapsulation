#include "Entity.h"

void Entity::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void Entity::move(int x, int y)
{
	posX += x;
	posY += y;
}
