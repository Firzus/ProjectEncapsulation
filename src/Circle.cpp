#include "Circle.h"
#include <iostream>

void Circle::bounceOfEntity(Entity* other)
{
	// Cercle
	Circle* otherCircle = dynamic_cast<Circle*>(other);
	if (otherCircle) {
		float dx = posX - otherCircle->getPosX();
		float dy = posY - otherCircle->getPosY();
		float distanceSquared = dx * dx + dy * dy;

		if (distanceSquared == 0) 
		{
			return;
		}

		// Normalize dx and dy vectors
		float distance = std::sqrt(distanceSquared);
		float normalX = dx / distance;
		float normalY = dy / distance;

		// Calculate the reflection vectors of X and Y
		float dotProduct = dirX * normalX + dirY * normalY;
		float reflectX = dirX - 2 * dotProduct * normalX;
		float reflectY = dirY - 2 * dotProduct * normalY;

		// Calculate initial speed and new magnitude to normalize reflection vectors
		float initialSpeed = std::sqrt(dirX * dirX + dirY * dirY);
		float magnitude = std::sqrt(reflectX * reflectX + reflectY * reflectY);

		// Calculate new directions with the new values
		int newDirX = reflectX / magnitude * initialSpeed;
		int newDirY = reflectY / magnitude * initialSpeed;

		// Correct differences when float values are converted to int value
		int initialAbsSum = std::abs(dirX) + std::abs(dirY);
		int absSum = std::abs(newDirX) + std::abs(newDirY);
		if (absSum != initialAbsSum)
		{
			if (absSum > initialAbsSum)
			{
				// If the new speed is greater than the initial speed, 
				// decrease the greatest value between newDirX and newDirY
				if (std::abs(newDirX) >= std::abs(newDirY)) 
				{
					newDirX = (newDirX > 0) ? newDirX - (absSum - initialAbsSum) : newDirX + (absSum - initialAbsSum);
				}
				else 
				{
					newDirY = (newDirY > 0) ? newDirY - (absSum - initialAbsSum) : newDirY + (absSum - initialAbsSum);
				}
			}
			else 
			{
				// If the new speed is lesser than the initial speed, 
				// increase the lowest value between newDirX and newDirY
				if (std::abs(newDirX) >= std::abs(newDirY)) 
				{
					newDirX = (newDirX > 0) ? newDirX + (initialAbsSum - absSum) : newDirX - (initialAbsSum - absSum);
				}
				else 
				{
					newDirY = (newDirY > 0) ? newDirY + (initialAbsSum - absSum) : newDirY - (initialAbsSum - absSum);
				}
			}
		}

		// Set the new direction
		setDirection(newDirX, newDirY);
	}
}

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