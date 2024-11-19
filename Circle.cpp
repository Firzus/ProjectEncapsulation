#include "Circle.h"
#include <iostream>

void Circle::setColor(const ColorRGBA& newColor)
{
	color = newColor;
}

void Circle::onCollide(Entity* other)
{
	std::cout << label << " collided with " << other->getLabel() << std::endl;
	color = ColorRGBA(0, 0, 255, 255);
}

bool Circle::isColliding(Entity* other)
{
	// Cercle
	Circle* otherCircle = dynamic_cast<Circle*>(other);
	if (otherCircle) {
		float dx = posX - otherCircle->getPosX();
		float dy = posY - otherCircle->getPosY();
		float distanceSquared = dx * dx + dy * dy;
		float radiusSum = radius + otherCircle->getRadius();
		return distanceSquared <= radiusSum * radiusSum;
	}

	// Others

	//
	//
	//

	return false;
}
