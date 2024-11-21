#pragma once

#include <string>
#include <iostream>
#include "ColorRGBA.h"

class Entity
{
protected:
	int posX = 0, posY = 0;
	int dirX = 0, dirY = 0;
	std::string label;
	int speed = 1;

public:
    virtual ~Entity() = default;

	virtual void draw() const = 0;

	virtual void setPosition(int x, int y);
	virtual void move();

	// Physics
	virtual void bounceOfEntity(Entity* other) = 0;
	virtual bool isColliding(Entity* other) = 0;

	// Getters and Setters
	std::string getLabel() const { return label; }
	int getPosX() const { return posX; }
	int getPosY() const { return posY; }

	void setDirX(int newDirX) { dirX = newDirX; }
	void setDirY(int newDirY) { dirY = newDirY; }
	int getDirX() const { return dirX; }
	int getDirY() const { return dirY; }
};
