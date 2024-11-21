#include "Entity.h"

void Entity::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void Entity::setDirection(int x, int y)
{
	dirX = x;
	dirY = y;
}

void Entity::move()
{
	posX += dirX * speed;
	posY += dirY * speed;
}
