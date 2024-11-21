#include "Bubble.h"

void Bubble::init()
{
	shapeColor1 = { 255, 0, 0, 255 };
	shapeColor2 = { 0, 255, 0, 255 };
	shapeColor3 = { 0, 0, 255, 255 };

	component->createCircle("circle1", 100, 100, shapeColor1, 25);
	component->createCircle("circle2", 300, 100, shapeColor2, 25);
	component->createCircle("circle3", 500, 500, shapeColor3, 25);

	component->getEntity<Circle>("circle1")->setDirection(8, 2);
	component->getEntity<Circle>("circle2")->setDirection(4, -6);
	component->getEntity<Circle>("circle3")->setDirection(2, 3);
}

void Bubble::update()
{
	// Physics and collisions
	for (auto it = component->getEntities().begin(); it != component->getEntities().end(); ++it)
	{
		// For each component in the list, check if it collided with another component of the same list
		for (auto other = component->getEntities().begin(); other != component->getEntities().end(); ++other)
		{
			if (it->second->isColliding(other->second))
			{
				it->second->bounceOfEntity(other->second);
			}
		}

		// Verify the actual component is a circle
		if (dynamic_cast<Circle*>(it->second))
		{
			Circle* circle = dynamic_cast<Circle*>(it->second);

			// Left and right screen collisions
			if (circle->getPosX() - circle->getRadius() <= 0 ||
				circle->getPosX() + circle->getRadius() >= window->getWindowWidth())
			{
				it->second->setDirection(-it->second->getDirX(), it->second->getDirY());
			}

			// Up and down screen collisions
			if (circle->getPosY() - circle->getRadius() <= 0 ||
				circle->getPosY() + circle->getRadius() >= window->getWindowHeight())
			{
				circle->setDirection(circle->getDirX(), -circle->getDirY());
			}
		}
	}

	// Call the move function for every components in the list
	for (auto it = component->getEntities().begin(); it != component->getEntities().end(); ++it)
	{
		if (it->second != nullptr)
		{
			it->second->move();
		}
	}
}
