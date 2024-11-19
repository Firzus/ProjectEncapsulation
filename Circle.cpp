#include "Circle.h"

bool Circle::isColliding(Entity* other)
{
	// Cercle
	Circle* otherCircle = dynamic_cast<Circle*>(other);
	if (otherCircle) {
		int dx = posX - otherCircle->getPosX();
		int dy = posY - otherCircle->getPosY();
		int distanceSquared = dx * dx + dy * dy;
		float radiusSum = radius + otherCircle->getRadius();
		return distanceSquared <= radiusSum * radiusSum;
	}

	// Others

	//
	//
	//

	return false;
}