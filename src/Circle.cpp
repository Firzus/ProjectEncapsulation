#include "Circle.h"

#include "Quadrilateral.h"
#include "Sprite.h"

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

		// Correct position to avoid bad collisions
		if (distance < radius + otherCircle->getRadius()) 
		{
			float overlap = (radius + otherCircle->getRadius()) - distance;

			float adjustX = overlap * dx / distance / 2.0f;
			float adjustY = overlap * dy / distance / 2.0f;

			posX += adjustX;
			posY += adjustY;

			otherCircle->setPosition(
				otherCircle->getPosX() - adjustX,
				otherCircle->getPosY() - adjustY);
		}

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
		dirX = newDirX;
		dirY = newDirY;

		move();
	}
}

bool Circle::isColliding(Entity* other)
{
	Circle* otherCircle = dynamic_cast<Circle*>(other);
	if (otherCircle) {
		int dx = posX - otherCircle->getPosX();
		int dy = posY - otherCircle->getPosY();
		int distanceSquared = dx * dx + dy * dy;
		float radiusSum = radius + otherCircle->getRadius();
		return distanceSquared <= radiusSum * radiusSum;
	}

	Quadrilateral* otherRect = dynamic_cast<Quadrilateral*>(other);
	if (otherRect) {
		// Récupérer les dimensions et la position du rectangle
		float rectX = otherRect->getPosX();
		float rectY = otherRect->getPosY();
		float rectWidth = otherRect->getWidth();
		float rectHeight = otherRect->getHeight();

		// Trouver le point le plus proche sur le rectangle par rapport au centre du cercle
		float closestX = std::max(rectX, std::min((float)posX, rectX + rectWidth));
		float closestY = std::max(rectY, std::min((float)posY, rectY + rectHeight));

		// Calculer la distance entre le cercle et ce point
		float dx = posX - closestX;
		float dy = posY - closestY;

		// Si la distance au carré est inférieure ou égale au rayon au carré, il y a collision
		return (dx * dx + dy * dy) <= (radius * radius);
	}

	// Sprite
	Sprite* otherSprite = dynamic_cast<Sprite*>(other);
	if (otherSprite) {
		// Récupérer les dimensions et la position du sprite
		float spriteX = otherSprite->getPosX();
		float spriteY = otherSprite->getPosY();
		float spriteWidth = otherSprite->getWidth();
		float spriteHeight = otherSprite->getHeight();
		// Trouver le point le plus proche sur le sprite par rapport au centre du cercle
		float closestX = std::max(spriteX, std::min((float)posX, spriteX + spriteWidth));
		float closestY = std::max(spriteY, std::min((float)posY, spriteY + spriteHeight));
		// Calculer la distance entre le cercle et ce point
		float dx = posX - closestX;
		float dy = posY - closestY;
		// Si la distance au carré est inférieure ou égale au rayon au carré, il y a collision
		return (dx * dx + dy * dy) <= (radius * radius);
	}

	// Others

	//
	//
	//

	// No collision
	return false;
}